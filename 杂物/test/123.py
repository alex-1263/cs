class File:
    def __init__(self, name, address, protection, length):
        self.name = name
        self.address = address
        self.protection = protection
        self.length = length

class FileSystem:
    def __init__(self):
        self.files = []

    def login(self):
        # 用户登录逻辑
        pass

    def list_files(self):
        for file in self.files:
            print("文件名：", file.name)
            print("物理地址：", file.address)
            print("保护码：", file.protection)
            print("文件长度：", file.length)
            print("")

    def create_file(self):
        name = input("请输入文件名：")
        protection = input("请输入保护码：")
        length = int(input("请输入文件长度："))
        file = File(name, None, protection, length)
        self.files.append(file)
        print("文件创建成功。")

    def delete_file(self):
        name = input("请输入要删除的文件名：")
        for file in self.files:
            if file.name == name:
                self.files.remove(file)
                print("文件删除成功。")
                return
        print("未找到文件。")

    def open_file(self):
        name = input("请输入要打开的文件名：")
        for file in self.files:
            if file.name == name:
                # 打开文件逻辑
                print("文件", name, "已打开。")
                return
        print("未找到文件。")

    def close_file(self):
        name = input("请输入要关闭的文件名：")
        # 关闭文件逻辑
        print("文件", name, "已关闭。")

    def read_file(self):
        name = input("请输入要读取的文件名：")
        length = int(input("请输入要读取的字节数："))
        # 从文件中读取数据的逻辑
        print("从文件", name, "读取了", length, "字节。")

    def write_file(self):
        name = input("请输入要写入的文件名：")
        data = input("请输入要写入的数据：")
        # 向文件中写入数据的逻辑
        print("向文件", name, "写入了数据。")

    def execute_command(self, command):
        if command == "1":
            self.create_file()
        elif command == "2":
            self.delete_file()
        elif command == "3":
            self.open_file()
        elif command == "4":
            self.close_file()
        elif command == "5":
            self.read_file()
        elif command == "6":
            self.write_file()
        elif command == "7":
            self.list_files()
        else:
            print("无效的命令。")

# 创建文件系统示例
file_system = FileSystem()
# 用户登录
file_system.login()
while True:
    print("文件系统菜单：")
    print("1. 创建文件")
    print("2. 删除文件")
    print("3. 打开文件")
    print("4. 关闭文件")
    print("5. 读取文件")
    print("6. 写入文件")
    print("7. 列出文件")
    print("8. 退出")
    choice = input("请输入您的选择：")
    if choice == "8":
        break
    file_system.execute_command(choice)
