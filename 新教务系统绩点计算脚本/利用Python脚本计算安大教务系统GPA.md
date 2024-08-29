# 利用Python脚本计算安大教务系统GPA

## 目录
- [利用Python脚本计算安大教务系统GPA](#利用python脚本计算安大教务系统gpa)
  - [目录](#目录)
  - [背景介绍](#背景介绍)
  - [为什么选择Playwright](#为什么选择playwright)
  - [如何运行脚本](#如何运行脚本)
    - [环境安装](#环境安装)
    - [运行步骤](#运行步骤)
  - [脚本解读](#脚本解读)
    - [登录教务系统](#登录教务系统)
    - [获取成绩数据](#获取成绩数据)
    - [计算平均学分绩点](#计算平均学分绩点)
    - [处理异常情况](#处理异常情况)
    - [关闭浏览器](#关闭浏览器)
  - [总结](#总结)
  - [完整代码](#完整代码)

## 背景介绍
在学校生活中，绩点（GPA）是学生评价自己学习成绩的重要指标。然而，安大新的教务系统只能查看各门课程的单独成绩，而无法直接查看总的平均学分绩点。这给很多同学带来了不便，尤其是需要频繁查阅GPA时。因此，我编写了一个Python脚本，通过自动化登录教务系统并抓取课程信息，来计算平均学分绩点(GPA)。

这个脚本使用了 **Playwright** 库来实现浏览器自动化操作，帮助用户在不需要手动登录和计算的情况下快速获得GPA。

## 为什么选择Playwright
在实现自动化浏览器操作时，Playwright相较于其他工具（如Selenium）具有以下几个优势：
- **支持多种浏览器**：Playwright支持Chromium、Firefox、WebKit等多个浏览器引擎，灵活性强。
- **自动等待页面加载**：Playwright具有智能等待机制，减少手动设置等待时间的需要，提高脚本的可靠性。
- **跨平台支持**：支持Windows、MacOS、Linux等多种操作系统，便于在不同环境中运行。
- **强大的调试功能**：Playwright提供丰富的调试选项，比如可以选择无头模式或带界面的模式，方便调试。

## 如何运行脚本

### 环境安装
要运行这个脚本，首先需要安装相关依赖。请确保你已安装Python 3.7+，并按以下步骤操作：

1. **安装依赖库：**
   ```bash
   pip install playwright
   ```
   
2. **安装浏览器引擎：**
   Playwright需要安装对应的浏览器引擎，运行以下命令：
   ```bash
   playwright install
   ```

### 运行步骤
1. 打开终端或命令行，输入以下命令运行脚本：
   ```bash
   python script_name.py
   ```
2. 脚本运行时，会提示输入学号和密码，请按照提示操作。

运行完成后，脚本会自动计算并输出你的总学分和平均学分绩点（GPA）。

## 脚本解读

### 登录教务系统
```python
def login_to_ahu_jw(page):
    page.goto("https://jw.ahu.edu.cn/student/login?refer=https://jw.ahu.edu.cn/student/home")
    page.get_by_role("button", name=" 统一身份认证登录").click()
    page.get_by_placeholder("用户名").fill(学号)
    page.get_by_placeholder("密码").fill(密码)
    page.wait_for_load_state("networkidle")
    page.click('.landing_btn_bg')
    page.get_by_role("link", name="我的成绩").click()
    page.wait_for_load_state("networkidle")
```
在脚本的这一部分，我们使用了Playwright的`page`对象来自动化地打开安大教务系统的登录页面，填写用户名和密码，点击登录按钮，并等待页面加载完成。通过这个函数，用户无需手动操作，脚本会自动处理登录过程。

### 获取成绩数据
```python
# Switch to the iframe
frame = page.frame_locator("iframe[name=\"e-home-iframe-1\"]")
    
# Extract course information
rows = frame.get_by_role("row")
```
登录成功后，脚本将切换到显示成绩的iframe页面。使用Playwright的`frame_locator`方法，我们定位到包含成绩的表格。接下来，脚本从表格中提取每一行的数据。

### 计算平均学分绩点
```python
total_credits = 0
total_weighted_grade = 0

for row in rows.all()[1:]:  # Skip header row
    course_name = row.get_by_role("cell").first.inner_text().strip()
    credits = row.get_by_role("cell").nth(1).inner_text().strip()
    grade = row.get_by_role("cell").nth(2).inner_text().strip()
    
    try:
        credits = float(credits)
        grade = float(grade)
        
        if credits > 0 and grade > 0:
            total_credits += credits
            total_weighted_grade += credits * grade
            print(f"Course: {course_name}, Credits: {credits}, Grade: {grade}")
        else:
            print(f"Skipping course: {course_name} (incomplete data)")
    except ValueError:
        print(f"Error processing course: {course_name}")
```
在这部分代码中，脚本逐行读取课程信息，并提取课程名称、学分和成绩。如果数据有效（学分和成绩均大于0），则将该课程的学分乘以成绩，累加到总学分和加权成绩中。

### 处理异常情况
```python
if total_credits > 0:
    gpa = total_weighted_grade / total_credits
    print(f"\nTotal Credits: {total_credits}")
    print(f"Average GPA: {gpa}")
else:
    print("No valid course data found.")
```
当所有课程处理完毕后，脚本会根据总学分和加权成绩计算平均学分绩点（GPA），并将结果打印出来。如果没有有效的课程数据，脚本会输出提示信息。

### 关闭浏览器
最后，脚本关闭浏览器：
```python
context.close()
browser.close()
```
这一部分代码确保脚本在完成所有操作后正确释放资源，关闭浏览器以避免内存泄漏或不必要的资源占用。

## 总结
通过这个Python脚本，我们能够自动化地登录安大的教务系统，抓取课程成绩数据并计算总学分绩点（GPA）。使用Playwright库，大大简化了浏览器自动化的实现过程，使得即便没有Python基础的同学，也能通过简单的命令行操作获得自己的GPA。

Playwright的强大功能和简单易用性，使得该工具成为了处理此类自动化任务的绝佳选择。如果你有类似的需求，可以考虑学习和使用这个库来简化日常操作。

## 完整代码
```python
from playwright.sync_api import Playwright, sync_playwright, expect

def login_to_ahu_jw(page):
    page.goto("https://jw.ahu.edu.cn/student/login?refer=https://jw.ahu.edu.cn/student/home")
    page.get_by_role("button", name=" 统一身份认证登录").click()
    page.get_by_placeholder("用户名").fill(学号)
    page.get_by_placeholder("密码").fill(密码)
    page.wait_for_load_state("networkidle")
    page.click('.landing_btn_bg')
    page.get_by_role("link", name="我的成绩").click()
    page.wait_for_load_state("networkidle")

def run(playwright: Playwright) -> None:
    browser = playwright.chromium.launch(headless=False)
    context = browser.new_context()
    page = context.new_page()
    
    login_to_ahu_jw(page)
    
    # Switch to the iframe
    frame = page.frame_locator("iframe[name=\"e-home-iframe-1\"]")
    
    # Extract course information
    rows = frame.get_by_role("row")
    total_credits = 0
    total_weighted_grade = 0
    
    for row in rows.all()[1:]:  # Skip header row
        course_name = row.get_by_role("cell").first.inner_text().strip()
        credits = row.get_by_role("cell").nth(1).inner_text().strip()
        grade = row.get_by_role("cell").nth(2).inner_text().strip()
        
        try:
            credits = float(credits)
            grade = float(grade)
            
            if credits > 0 and grade > 0:
                total_credits += credits
                total_weighted_grade += credits * grade
                print(f"Course: {course_name}, Credits: {credits}, Grade: {grade}")
            else:
                print(f"Skipping course: {course_name} (incomplete data)")
        except ValueError:
            print(f"Error processing course: {course_name}")
    
    if total_credits > 0:
        gpa = total_weighted_grade / total_credits
        print(f"\nTotal Credits: {total_credits}")
        print(f"Average GPA: {gpa}")
    else:
        print("No valid course data found.")
    
    # Close browser
    context.close()
    browser.close()

with sync_playwright() as playwright:
    学号 = input("请输入学号: ")
    密码 = input("请输入密码: ")
    run(playwright)
```