#include <iostream>
#include<string>
#include<fstream>//头文件的包含
using namespace std;

void test01() {
    //包含头文件fstream
    //创建流对象
    //文件输出流cpu到内存
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
    //创建读文件对象
    //文件输入流，文件到cpu
    ifstream ioo;
    //打开文件并判断是否打开文件成功。
    ioo.open("test.txt", ios::in);
    if (!ioo.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    //读数据，四种读取方式
    //第一种
   /* char buf[1024] = { 0 };
    while (ioo >> buf) {
        cout << buf<< endl;
    }*/
    //第二种
    char buf[1024] = { 0 };
    while (ioo.getline(buf, sizeof(buf))) {
        cout << buf << endl;
    }
    //第三种
    string n;
    while (getline(ioo, n)) {
        cout << n << endl;
    }
    char c;
    while ((c = ioo.get()) != EOF) {
        cout << c;
    }
    //关闭文件
    ioo.close();
}

int main()
{
    test01();
    std::cout << "Hello World!\n";
    system("pause");
    return 0;
}
