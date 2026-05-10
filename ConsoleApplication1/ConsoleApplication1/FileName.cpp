#include<iostream>
#include<string.h>
using namespace std;


class Student {
public:
	string Name;
	long long ID;
	void setName() {
		cout << "Enter name: " << endl;
		cin >> Name;
	}
	void setID() {
		cout << "Enter ID: " << endl;
		cin >> ID;
	}
	void info() {
				cout << "Name: " << Name << endl;
				cout << "ID: " << ID << endl;
	}
};

int main() {
	Student s1;
	s1.setName();
	s1.setID();
	s1.info();
	return 0;
}