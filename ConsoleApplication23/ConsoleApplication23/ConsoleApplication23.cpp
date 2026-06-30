#include <iostream>
#include<string>
#include<fstream>//头文件的包含
using namespace std;

void test01() {
    //包含头文件fstream
    //创建流对象
    ofstream ofs;
    //指定打开方式
    ofs.open("test.txt", ios::out);
    //写内容
    ofs << "姓名：张三" << endl;
    ofs << "姓名：张三" << endl;
    ofs << "姓名：张三" << endl;
    ofs << "姓名：张三" << endl;
    ofs << "姓名：张三" << endl;
    ofs << "姓名：张三" << endl;
    ofs << "姓名：张三" << endl;
    ofs << "姓名：张三" << endl;
    ofs << "姓名：张三" << endl;
    ofs << "姓名：张三" << endl;
    //关闭文件
    ofs.close();
}

int main()
{
    test01();
    std::cout << "Hello World!\n";
    system("pause");
    return 0;
}
