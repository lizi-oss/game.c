#include<iostream>
using namespace std;
#include<string>

struct Student
{
	string name;   // 姓名
	int age;       // 年龄
	string temper; // 性格/评价
};

int main()
{
	// 第一个学生
	Student s1;
	s1.name = "李文爽";
	s1.age = 19;
	s1.temper = "no good，她人太坏了，她骂我，她欺负我，她还回家，她们俩出去玩都不带我";
	cout << s1.name << endl;
	cout << s1.age << endl;
	cout << s1.temper << endl;
	cout << endl; // 空一行，方便区分

	// 第二个学生
	Student s2;
	s2.name = "李晗";
	s2.age = 19;
	s2.temper = "a little good，她人还好一点，但是她也回家了，并且她们俩出去玩都不带我";
	cout << s2.name << endl;
	cout << s2.age << endl;
	cout << s2.temper << endl;

	return 0;
}