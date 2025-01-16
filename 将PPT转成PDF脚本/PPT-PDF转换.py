import os
import win32com.client
from pathlib import Path

def convert_ppt_to_pdf(input_folder):
    # 初始化PowerPoint应用
    powerpoint = win32com.client.Dispatch("Powerpoint.Application")
    powerpoint.Visible = True
    
    # 初始化Acrobat
    adobe = win32com.client.Dispatch("AcroExch.App")
    
    # 获取所有ppt和pptx文件
    ppt_files = list(Path(input_folder).glob("*.ppt")) + list(Path(input_folder).glob("*.pptx"))
    
    try:
        for ppt_path in ppt_files:
            # 转换文件路径为绝对路径
            abs_path = str(ppt_path.absolute())
            pdf_path = str(ppt_path.with_suffix('.pdf').absolute())
            
            print(f"正在处理: {ppt_path.name}")
            
            # 打开PPT文件
            presentation = powerpoint.Presentations.Open(abs_path)
            
            try:
                # 先将PPT另存为PDF
                presentation.SaveAs(pdf_path, 32)  # 32 代表 PDF 格式
                presentation.Close()
                
                # 使用Acrobat优化PDF
                if os.path.exists(pdf_path):
                    avdoc = win32com.client.Dispatch("AcroExch.AVDoc")
                    if avdoc.Open(pdf_path, pdf_path):
                        pdoc = avdoc.GetPDDoc()
                        # 可以在这里添加PDF优化设置
                        pdoc.Save(1, pdf_path)  # 1代表完整保存
                        pdoc.Close()
                        avdoc.Close(True)
                        
                print(f"转换成功: {pdf_path}")
                
            except Exception as e:
                print(f"转换失败: {ppt_path.name}")
                print(f"错误信息: {str(e)}")
                continue
                
    finally:
        # 清理资源
        powerpoint.Quit()
        adobe.Exit()



if __name__ == "__main__":
    folder_path = r"C:\my_files"  # 替换为您的文件夹路径
    convert_ppt_to_pdf(folder_path)
