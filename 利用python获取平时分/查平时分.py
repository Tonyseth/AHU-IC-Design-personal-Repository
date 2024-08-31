from playwright.sync_api import Playwright, sync_playwright, expect
import pandas as pd
import csv

def login_to_ahu_jw(page):
    page.goto("https://jw.ahu.edu.cn/student/login?refer=https://jw.ahu.edu.cn/student/home")
    page.get_by_role("button", name=" 统一身份认证登录").click()
    page.get_by_placeholder("用户名").fill("替换为你的学号")
    page.get_by_placeholder("密码").fill("替换为你的密码")
    page.wait_for_load_state("networkidle")
    page.click('.landing_btn_bg')
    page.get_by_role("link", name="我的成绩").click()
    page.wait_for_load_state("networkidle")

def login_to_ahu_one(page):
    page.goto("https://one.ahu.edu.cn/cas/login?service=https%3A%2F%2Fone.ahu.edu.cn%2Ftp_up%2Fview")
    page.get_by_placeholder("用户名").fill("替换你的学号")
    page.get_by_placeholder("密码").fill("替换为你的密码")
    page.get_by_placeholder("密码").press("Enter")
    #page.get_by_role("link", name="进入校园综合服务门户").click()
    
    with page.expect_popup() as page1_info:
        page.wait_for_load_state("networkidle")
        page.get_by_role("link", name=" 数据中心").click()
        print("进入数据中心成功")
    page1 = page1_info.value
    
    try:
        page1.goto("https://wvpn.ahu.edu.cn/https/77726476706e69737468656265737421fff944d226387d1e7b0c9ce29b5b/idc/view?m=idc#act=idc/dataFeedback/infoShow/infoSetShow/1449938969329664", timeout=60000)
        print("成功导航到指定页面")
    except TimeoutError:
        print("导航超时，继续执行...")
    
    page1.wait_for_load_state("networkidle", timeout=60000)
    page1.wait_for_timeout(5000)  # 额外等待5秒
    
    try:
        page1.wait_for_selector("#myDataTable", timeout=60000)
        print("成功找到 #myDataTable 元素")
    except TimeoutError:
        print("等待 #myDataTable 超时，继续执行...")
    
    return page1


def run(playwright: Playwright) -> None:
    browser = playwright.chromium.launch(headless=False)
    context = browser.new_context()
    page = context.new_page()

    # 第一部分: 获取课程代码和名称
    login_to_ahu_jw(page)
    
    frame = page.frame_locator("iframe[name=\"e-home-iframe-1\"]")
    rows = frame.locator('tr').all()
    
    course_codes = []
    course_names = []
    for row in rows[1:]:
        cells = row.locator("td").all()
        if len(cells) >= 1:
            course_info = cells[0].inner_text().strip()
            parts = course_info.split('|')
            if len(parts) >= 1:
                course_name_code = parts[0].strip().split()
                if len(course_name_code) >= 2:
                    course_names.append(' '.join(course_name_code[:-1]))
                    course_codes.append(course_name_code[-1])

    # 第二部分: 获取详细成绩信息
    page1 = login_to_ahu_one(page)
    
    all_grade_data = []
    total_pages = len(page1.query_selector_all(".paginate_button:not(.next):not(.previous)"))
    
    for page_num in range(1, total_pages + 1):
        grade_data = extract_data_from_table(page1)
        all_grade_data.extend(grade_data)
        
        if page_num < total_pages:
            next_button = page1.query_selector(".paginate_button.next")
            if next_button:
                next_button.click()
                page1.wait_for_load_state("networkidle")
                page1.wait_for_timeout(5000)

    # 合并数据
    df1 = pd.DataFrame({'课程代码': course_codes, '课程名称': course_names})
    df2 = pd.DataFrame(all_grade_data)
    
    merged_df = pd.merge(df2, df1, left_on='课程号', right_on='课程代码', how='left')
    merged_df = merged_df.drop('课程代码', axis=1)  # 删除重复的课程代码列
    # 调整列顺序，将课程名称移动到课程代码的右边
    cols = list(merged_df.columns)
    course_name_index = cols.index('课程名称')
    cols.insert(cols.index('课程号') + 1, cols.pop(course_name_index))
    merged_df = merged_df[cols]
    # 保存到Excel
    merged_df.to_excel('合并课程信息.xlsx', index=False)
    print("数据已保存到 '合并课程信息.xlsx'")

    context.close()
    browser.close()

def extract_data_from_table(page):
    rows = page.query_selector_all("#myDataTable tbody tr")
    grade_data = []
    for row in rows:
        cells = row.query_selector_all("td")
        if len(cells) >= 22:
            grade_data.append({
                "学年": cells[0].inner_text(),
                "学期": cells[1].inner_text(),
                "课程号": cells[3].inner_text(),
                "平时成绩": cells[4].inner_text(),
                "考试方式": cells[5].inner_text(),
                "分数类考试成绩": cells[8].inner_text(),
                "等级类考试成绩": cells[9].inner_text(),
                "课程成绩": cells[10].inner_text(),
                "学分": cells[16].inner_text(),
                "绩点": cells[17].inner_text()
            })
    return grade_data

with sync_playwright() as playwright:
    run(playwright)
