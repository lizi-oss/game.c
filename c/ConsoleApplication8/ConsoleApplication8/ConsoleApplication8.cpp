#include<iostream>
using namespace std;
#include<string.h>

struct student
{
	int id;
	string name;
	float marks;
};

struct teacher {
	int id;
	string name;
	float salary;
	struct student s[3];//结构体嵌套结构体，结构体数组。
};

int main()
{
	struct teacher t;
	cout << "Enter teacher details: id, name, salary" << endl;
	cin >> t.id;
	cin >> t.name;
	cin >> t.salary;
	cout << "Enter student details: id, name, marks" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> t.s[i].id;
		cin >> t.s[i].name;
		cin >> t.s[i].marks;
	}
	cout << "Teacher ID: " << t.id << endl;
	cout << "Teacher Name: " << t.name << endl;
	cout << "Teacher Salary: " << t.salary << endl;
	struct teacher* ptr = &t;//结构体指针
	ptr->name = "Rohit";
	cout << "Teacher Name (after update): " << ptr->name << endl;
	return 0;
}