#include<iostream>
using namespace std;
#include<string.h>

struct student {
	string name;
	int rollno;
	float marks;
}stu;

void display(student s) {
	cout << "Name: " << s.name << endl;
	cout << "Roll No: " << s.rollno << endl;
	cout << "Marks: " << s.marks << endl;
};

void input(student &s) {//student &s 就是：不用指针，也能在函数里修改原结构体，比指针简单，比普通传参好用。
	cout << "Enter Name: ";
	cin >> s.name;
	cout << "Enter Roll No: ";
	cin >> s.rollno;
	cout << "Enter Marks: ";
	cin >> s.marks;
}

// 结构体指针写法
//void input(student* s)
//{
//	cout << "Enter Name: ";
//	cin >> s->name;
//
//	cout << "Enter Roll No: ";
//	cin >> s->rollno;
//
//	cout << "Enter Marks: ";
//	cin >> s->marks;
//}如果下面用指针写法调用函数，就要改成：input(&stu); 因为函数参数是student* s，所以要传入地址。

int main() {
	input(stu);
	display(stu);
	return 0;
}