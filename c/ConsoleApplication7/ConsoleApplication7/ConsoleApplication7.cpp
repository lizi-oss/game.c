#include<iostream>
using namespace std;
#include<string>

struct Student
{
    string name = "";   // 姓名
    int age = 0;        // 年龄
    string temper = ""; // 性格/评价
};

int main() {
    Student s[3] = {
        {"李靓颖", 1, "可爱"},
        {"李靓颖01", 6, "魔童"},
        {"李靓颖02", 20, "超级无敌大坏蛋"}
    };

    // 修改前输出
    for (int i = 0; i < 3; i++) {
        cout << "修改前：" << endl;
        cout << "姓名：" << s[i].name << endl;
        cout << "年龄：" << s[i].age << endl;
        cout << "评价：" << s[i].temper << endl;
        cout << "-------------------------" << endl;
    }

    // 修改第2个学生
    s[0].name = "wyy";
    s[0].age = 19;
    s[0].temper = "超级无敌大好人";

    // 修改后输出
    for (int i = 0; i < 3; i++) {
        cout << "修改后：" << endl;
        cout << "姓名：" << s[i].name << endl;
        cout << "年龄：" << s[i].age << endl;
        cout << "评价：" << s[i].temper << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}
//致命问题：数字前加了 0 导致八进制错误
//你代码里这两行是罪魁祸首：
//cpp
//运行
//{ "李靓颖",01,"可爱" },
//{ "李靓颖01",06,"魔童" },
//在 C++ 中，以 0 开头的整数，会被编译器当成「八进制数」处理！
//八进制数只能用 0 - 7 这 8 个数字
//01 和 06 本身是合法的八进制（等于十进制的 1 和 6），但 VS 的链接器会把它当成潜在的格式错误，导致生成失败。
//更危险的是，如果写成 08、09，会直接编译报错。
//✅ 修正方法：去掉数字前面的 0