# 如何通过Python脚本获取智慧安大的平时分信息

---

## 目录
- [背景介绍](#背景介绍)
- [如何零基础运行Python脚本](#如何零基础运行python脚本)
- [分步解读Python脚本](#分步解读python脚本)
  - [登录智慧安大教务系统](#登录智慧安大教务系统)
  - [登录智慧安大数据中心](#登录智慧安大数据中心)
  - [获取课程代码和名称](#获取课程代码和名称)
  - [合并数据并导出Excel](#合并数据并导出excel)
  - [提取表格数据](#提取表格数据)
- [总结与互动](#总结与互动)

---

### 背景介绍

在安徽大学，我们无法通过常规方式查询各门课程的平时分，只有期末考试结束后能看到总成绩。其实，通过登录智慧安大网站，进入数据中心，并改变URL中的哈希标识符来触发JavaScript来更新页面，可以进入一个隐藏界面，查看每门课程的平时分信息。为了简化这一过程，我编写了一个Python脚本，能够自动获取并导出所有课程的平时分，并合并课程代码和名称生成一个完整的Excel文件。

---

### 如何零基础运行Python脚本

如果有python基础的同学可以跳过这一部分，直接查看脚本内容。以下是如何零基础运行Python脚本的步骤。

#### 安装Python

1. 首先，前往 [Python官网](https://www.python.org/downloads/) 下载并安装最新版本的Python。
2. 安装时务必勾选“Add Python to PATH”选项，以便能够在命令行中直接使用Python。

#### 安装依赖库

脚本依赖于`playwright`和`pandas`库，因此需要先安装这些依赖库。

1. 打开命令行（Windows用户可以使用CMD或PowerShell，macOS/Linux用户使用终端）。
2. 运行以下命令安装依赖库：

```bash
pip install pandas playwright
playwright install
```

#### 运行脚本

1. 将本文中的脚本复制到一个名为`ahu_grades.py`的文件中。
2. 在命令行中导航到脚本所在的目录，例如：

```bash
cd /path/to/script
```

3. 运行脚本：

```bash
python ahu_grades.py
```

4. 脚本将自动打开浏览器，登录智慧安大教务系统及数据中心，并获取平时分信息。最终结果将保存为Excel文件。

---

### 分步解读Python脚本

#### 登录智慧安大教务系统

脚本首先定义了一个`login_to_ahu_jw`函数，用于自动登录智慧安大的教务系统。主要步骤包括：

1. **导航到教务系统登录页面**：
   ```python
   page.goto("https://jw.ahu.edu.cn/student/login?refer=https://jw.ahu.edu.cn/student/home")
   ```

2. **模拟点击统一身份认证登录按钮，并输入用户名和密码**：
   ```python
   page.get_by_role("button", name=" 统一身份认证登录").click()
   page.get_by_placeholder("用户名").fill("替换为你的学号")
   page.get_by_placeholder("密码").fill("替换为你的密码")
   ```

3. **完成登录并进入成绩页面**：
   ```python
   page.get_by_role("link", name="我的成绩").click()
   ```

这个函数负责登录并进入到学生成绩页面，接下来的操作将基于该页面进行数据提取。

```python
def login_to_ahu_jw(page):
    page.goto("https://jw.ahu.edu.cn/student/login?refer=https://jw.ahu.edu.cn/student/home")
    page.get_by_role("button", name=" 统一身份认证登录").click()
    page.get_by_placeholder("用户名").fill("替换为你的学号")
    page.get_by_placeholder("密码").fill("替换为你的密码")
    page.wait_for_load_state("networkidle")
    page.click('.landing_btn_bg')
    page.get_by_role("link", name="我的成绩").click()
    page.wait_for_load_state("networkidle")
```

#### 登录智慧安大数据中心

##### 分步解读 `login_to_ahu_one` 函数

`login_to_ahu_one` 函数负责自动化登录智慧安大网站并导航到数据中心页面，从而提取需要的平时分信息。这个函数利用了Playwright库，通过模拟用户的浏览器行为来完成这一任务。接下来，我将详细解释这个函数的每一步。

```python
def login_to_ahu_one(page):
    page.goto("https://one.ahu.edu.cn/cas/login?service=https%3A%2F%2Fone.ahu.edu.cn%2Ftp_up%2Fview")
```
###### 1. 导航到登录页面
- `page.goto()` 方法用于导航到指定的URL，这里指向了智慧安大的登录页面。
- 这个URL包含了CAS单点登录系统的路径，它确保你访问的是登录门户页面。

```python
    page.get_by_placeholder("用户名").fill("替换为你的学号")
    page.get_by_placeholder("密码").fill("替换为你的密码")
    page.get_by_placeholder("密码").press("Enter")
```
###### 2. 填写用户名和密码并登录
- `page.get_by_placeholder("用户名").fill()`：此方法根据输入框的占位符（Placeholder）找到用户名输入框，并自动填入用户名 `替换为你的学号`。
- `page.get_by_placeholder("密码").fill()`：同样方式找到密码输入框，自动填入密码。
- `page.get_by_placeholder("密码").press("Enter")`：此方法模拟按下回车键，触发表单提交，开始登录过程。

这一步通过自动填写登录表单并提交，模拟了手动操作登录智慧安大网站的过程。

```python
    with page.expect_popup() as page1_info:
        page.wait_for_load_state("networkidle")
        page.get_by_role("link", name=" 数据中心").click()
        print("进入数据中心成功")
    page1 = page1_info.value
```
###### 3. 等待并进入数据中心
- `with page.expect_popup() as page1_info:`：该部分代码等待页面打开新窗口或标签页，并将该新窗口对象保存为 `page1_info`。这一点至关重要，因为数据中心页面会在新的弹出窗口中打开。
- `page.wait_for_load_state("networkidle")`：等待页面加载完成，此处的 `"networkidle"` 表示页面上的所有网络请求都已经完成，这确保了页面稳定加载。
- `page.get_by_role("link", name=" 数据中心").click()`：使用 `get_by_role` 方法找到名为“数据中心”的链接，并自动点击它，从而进入数据中心页面。

当弹出窗口打开后，`page1 = page1_info.value` 将新窗口赋值给 `page1` 变量，后续操作将在此窗口中进行。

```python
    try:
        page1.goto("https://wvpn.ahu.edu.cn/https/77726476706e69737468656265737421fff944d226387d1e7b0c9ce29b5b/idc/view?m=idc#act=idc/dataFeedback/infoShow/infoSetShow/1449938969329664", timeout=60000)
        print("成功导航到指定页面")
    except TimeoutError:
        print("导航超时，继续执行...")
```
###### 4. 导航到数据反馈页面
- `page1.goto()`：在新窗口 `page1` 中，导航到指定的URL，即目标数据反馈页面。
- `timeout=60000`：为加载页面设置了60秒的超时时间，确保即使网络较慢，页面也有足够时间加载。
- `try/except` 结构：如果页面在指定时间内未能加载成功，将捕获 `TimeoutError`，并继续执行后续操作，而不会导致整个脚本中断。这种处理方式增加了脚本的鲁棒性。

```python
    page1.wait_for_load_state("networkidle", timeout=60000)
    page1.wait_for_timeout(5000)  # 额外等待5秒
```
###### 5. 等待页面加载完成
- 再次使用 `wait_for_load_state("networkidle")` 方法，确保数据中心页面加载完成。
- `wait_for_timeout(5000)`：额外等待5秒时间，以确保所有数据及动态内容完全呈现，避免因页面加载延迟导致抓取失败。

```python
    try:
        page1.wait_for_selector("#myDataTable", timeout=60000)
        print("成功找到 #myDataTable 元素")
    except TimeoutError:
        print("等待 #myDataTable 超时，继续执行...")
```
###### 6. 等待并确认页面内容加载
- `wait_for_selector("#myDataTable")`：等待指定的CSS选择器 `#myDataTable` 出现，该选择器对应的是包含成绩数据的表格元素。这个操作确保页面中的关键信息已经呈现。
- 这里也使用了 `try/except` 结构，以捕获等待超时的异常。如果表格未能在指定时间内加载完成，脚本仍会继续执行。

```python
    return page1
```
###### 7. 返回数据中心页面对象
函数的最后，将数据中心页面 `page1` 返回，供后续步骤调用。这一页面包含了需要提取的平时分等成绩数据。

---

#### 获取课程代码和名称

##### 分步解读 `run` 函数

`run` 函数是脚本的主流程，它通过调用其他函数来完成整个自动化操作，包含登录教务系统、获取课程信息、获取详细成绩数据以及数据处理和保存。以下是对该函数的详细解读：

```python
def run(playwright: Playwright) -> None:
    browser = playwright.chromium.launch(headless=False)
    context = browser.new_context()
    page = context.new_page()
```

###### 1. 启动浏览器并创建页面上下文
- `browser = playwright.chromium.launch(headless=False)`：这一行代码使用Playwright启动一个Chromium浏览器实例。`headless=False` 意味着浏览器将在有UI界面的模式下运行，这样用户可以看到浏览器的操作过程。如果设为 `True`，浏览器将在后台无界面模式下运行。
  
- `context = browser.new_context()`：创建一个新的浏览器上下文（Context）。上下文类似于一个独立的浏览器窗口，每个上下文拥有自己的缓存、Cookie等。使用上下文可以避免不同页面之间的数据互相干扰。
  
- `page = context.new_page()`：在新创建的上下文中打开一个新的页面（相当于一个新的标签页），这个 `page` 对象是后续所有操作的主要对象。

```python
    # 第一部分: 获取课程代码和名称
    login_to_ahu_jw(page)
```

###### 2. 登录教务系统
- `login_to_ahu_jw(page)`：调用 `login_to_ahu_jw` 函数，该函数会自动化地登录教务系统并导航到成绩页面。这一步完成后，页面将停留在包含成绩信息的页面上，接下来我们可以提取课程的代码和名称。

```python
    frame = page.frame_locator("iframe[name=\"e-home-iframe-1\"]")
    rows = frame.locator('tr').all()
```

###### 3. 获取课程表格的行
- `frame = page.frame_locator("iframe[name=\"e-home-iframe-1\"]")`：这个语句通过 `frame_locator` 方法定位嵌入在页面中的 `iframe`，`iframe` 是一个嵌入到网页中的独立HTML文档。`"e-home-iframe-1"` 是该 `iframe` 的名称。
  
- `rows = frame.locator('tr').all()`：接着，脚本在 `iframe` 中找到所有的表格行元素（`tr`），并将它们存储在 `rows` 列表中。每个 `tr` 元素代表表格中的一行数据。

```python
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
```

###### 4. 提取课程代码和名称
- 初始化 `course_codes` 和 `course_names` 两个空列表，用于存储课程代码和课程名称。
  
- `for row in rows[1:]:`：循环遍历 `rows` 列表中的每一行。这里使用 `rows[1:]` 跳过第一行，因为第一行通常是表头，不包含具体数据。
  
- `cells = row.locator("td").all()`：在每一行中，选择所有单元格元素（`td`），并存储为 `cells` 列表。
  
- 如果 `cells` 列表中包含至少一个元素，则从第一个单元格（`cells[0]`）中提取课程信息。课程信息以 `|` 作为分隔符，因此使用 `split('|')` 分割字符串。
  
- 然后通过 `split()` 将课程名称和课程代码分开，并分别存储到 `course_names` 和 `course_codes` 列表中。

```python
    # 第二部分: 获取详细成绩信息
    page1 = login_to_ahu_one(page)
```

###### 5. 登录智慧安大并进入数据中心
- `page1 = login_to_ahu_one(page)`：调用 `login_to_ahu_one` 函数，这个函数会自动化登录智慧安大网站，导航到数据中心，并返回新打开的包含成绩数据的页面对象 `page1`。

```python
    all_grade_data = []
    total_pages = len(page1.query_selector_all(".paginate_button:not(.next):not(.previous)"))
```

###### 6. 初始化数据存储和分页计算
- 初始化 `all_grade_data` 空列表，用于存储从所有分页中提取的成绩数据。
  
- `total_pages = len(page1.query_selector_all(".paginate_button:not(.next):not(.previous)"))`：通过选择所有分页按钮来计算数据表的总页数。CSS选择器 `".paginate_button:not(.next):not(.previous)"` 选择所有不是 "下一页" 和 "上一页" 的分页按钮，从而确定总页数。

```python
    for page_num in range(1, total_pages + 1):
        grade_data = extract_data_from_table(page1)
        all_grade_data.extend(grade_data)
        
        if page_num < total_pages:
            next_button = page1.query_selector(".paginate_button.next")
            if next_button:
                next_button.click()
                page1.wait_for_load_state("networkidle")
                page1.wait_for_timeout(5000)
```

###### 7. 提取所有分页中的成绩数据
- `for page_num in range(1, total_pages + 1):`：遍历每一页数据。
  
- `grade_data = extract_data_from_table(page1)`：调用 `extract_data_from_table` 函数，从当前页提取成绩数据，并将其存储在 `grade_data` 列表中。
  
- `all_grade_data.extend(grade_data)`：将当前页的数据添加到 `all_grade_data` 列表中。
  
- `if page_num < total_pages:`：如果还未到最后一页，找到并点击 "下一页" 按钮。`next_button.click()` 模拟点击操作，然后使用 `wait_for_load_state("networkidle")` 确保页面加载完成，再等待5秒钟以保证数据完全呈现。

```python
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
```

###### 8. 数据合并与保存
- 使用 `pandas.DataFrame` 创建两个数据框：`df1` 包含课程代码和名称，`df2` 包含从数据中心提取的成绩数据。
  
- `pd.merge(df2, df1, left_on='课程号', right_on='课程代码', how='left')`：合并两个数据框。`df2` 中的 "课程号" 列与 `df1` 中的 "课程代码" 列进行匹配合并。`how='left'` 表示使用左连接，保留成绩数据中的所有行，即使某些行可能缺少对应的课程信息。
  
- `merged_df = merged_df.drop('课程代码', axis=1)`：合并后会有重复的课程代码列，使用 `drop` 方法将其删除。
  
- 通过调整列顺序，将课程名称移动到课程号的右边，使得最终的数据框格式更加清晰。
  
- `merged_df.to_excel('合并课程信息.xlsx', index=False)`：将合并后的数据保存为Excel文件 `合并课程信息.xlsx`，不包含行索引。
  
- `print("数据已保存到 '合并课程信息.xlsx'")`：在控制台输出提示信息，告知用户数据保存成功。

```python
    context.close()
    browser.close()
```

###### 9. 关闭浏览器上下文与实例
- `context.close()`：关闭浏览器上下文，释放资源。
  
- `browser.close()`：关闭浏览器实例，结束自动化操作。

---

#### 合并数据并导出Excel

最后，脚本将提取的成绩信息与课程代码和名称进行合并，并导出为Excel文件：

1. **创建DataFrame对象，分别存储课程信息和成绩信息**：
   ```python
   df1 = pd.DataFrame({'课程代码': course_codes, '课程名称': course_names})
   df2 = pd.DataFrame(all_grade_data)
   ```

2. **通过课程代码进行数据合并**：
   ```python
   merged_df = pd.merge(df2, df1, left_on='课程号', right_on='课程代码', how='left')
   ```

3. **将合并后的数据保存为Excel文件**：
   ```python
   merged_df.to_excel('合并课程信息.xlsx', index=False)
   ```

导出的Excel文件将包含每门课程的平时分、课程名称、成绩等详细信息。

---

####  `extract_data_from_table` 函数

`extract_data_from_table` 函数负责从智慧安大的数据中心页面提取包含课程成绩的表格数据，并将其存储在一个结构化的列表中。这一函数使用Playwright库来查询表格元素，并将其中的数据逐行提取出来。接下来，我将详细解释这个函数的每一步。

```python
def extract_data_from_table(page):
    rows = page.query_selector_all("#myDataTable tbody tr")
```

##### 1. 查询表格行
- `page.query_selector_all("#myDataTable tbody tr")`：此方法用于选择页面中的所有符合指定CSS选择器的元素。在这里，它选择了 `#myDataTable` 表格内 `tbody`（表格主体）中的所有行（`tr`）。
  - `#myDataTable` 是目标表格的ID，通常包含课程成绩数据。
  - `tbody tr` 确保我们只选择表格主体部分的行，而不是表头部分。

选择后的 `rows` 是一个行元素的列表，每个元素对应表格中的一行。

```python
    grade_data = []
```

##### 2. 初始化数据存储
- 初始化一个空列表 `grade_data`，用于存储从每一行提取出的成绩数据。每一行的成绩数据将以字典的形式存储在这个列表中。

```python
    for row in rows:
        cells = row.query_selector_all("td")
```

##### 3. 遍历每一行并获取单元格数据
- `for row in rows:`：通过循环遍历所有的表格行，逐行处理数据。
- `row.query_selector_all("td")`：在每一行 `row` 中，使用CSS选择器 `td` 来选择所有的单元格元素。这将返回一个包含该行中所有单元格的列表 `cells`。

每行的单元格数通常与表格的列数相对应，每个单元格（`td`）中包含着具体的数据，如课程号、成绩等。

```python
        if len(cells) >= 22:
```

##### 4. 数据完整性检查
- `if len(cells) >= 22:`：检查当前行中是否包含至少22个单元格。这个检查确保只处理数据完整的行，避免由于空行或格式不正确的行导致错误。
  - 这里假设表格中每一行应包含至少22个数据项（即22列），如果少于22列，则可能是无效行。

```python
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
```

##### 5. 提取并存储数据
- 如果该行包含足够多的单元格，脚本会从 `cells` 列表中按顺序提取数据，并将其存储为字典。
  - `cells[0].inner_text()`：提取第1列（`学年`）的数据。
  - `cells[1].inner_text()`：提取第2列（`学期`）的数据。
  - `cells[3].inner_text()`：提取第4列（`课程号`）的数据。
  - `cells[4].inner_text()`：提取第5列（`平时成绩`）的数据。
  - `cells[5].inner_text()`：提取第6列（`考试方式`）的数据。
  - `cells[8].inner_text()`：提取第9列（`分数类考试成绩`）的数据。
  - `cells[9].inner_text()`：提取第10列（`等级类考试成绩`）的数据。
  - `cells[10].inner_text()`：提取第11列（`课程成绩`）的数据。
  - `cells[16].inner_text()`：提取第17列（`学分`）的数据。
  - `cells[17].inner_text()`：提取第18列（`绩点`）的数据。

- 提取的这些数据项构成了一门课程的完整成绩信息，并以字典的形式存储。然后，使用 `grade_data.append()` 方法将这个字典追加到 `grade_data` 列表中。

```python
    return grade_data
```

##### 6. 返回数据
- `return grade_data`：函数最后返回包含所有成绩数据的 `grade_data` 列表。这个列表中的每一项都是一个字典，代表一门课程的成绩信息。

---



### 总结

通过本博客的介绍，可以轻松获取安徽大学智慧安大系统中隐藏的平时分信息，并导出为完整的Excel表格。这种自动化技术不仅可以提高查询效率，还能够帮助你将分散的信息整合为更加直观的数据表格。。对于没有编程基础的同学，也可以按照步骤快速上手。如果你对Python感兴趣，建议深入学习Playwright库，它可以帮助你在更多场景下实现自动化操作。
希望本篇博客能够帮助你更加便捷地管理和查看自己的学业成绩。通过自动化脚本，节省了手动查询的时间。如果有任何问题，欢迎在评论区留言交流，或者在[GitHub](https://github.com/Tonyseth/AHU-IC-Design-personal-Repository)上提交你的问题和改进建议，一起学习与进步！

---



