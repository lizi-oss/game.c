#include<iostream>
#include<string>
using namespace std;

class Building;//不需要延迟创建，自然不需要指针。
//你现在必须用指针的真正根源
//因为你要写友元成员函数：

class GoodDay {
public:
	GoodDay();
	void visit1();
	void visit2();
	~GoodDay();
private:
	Building* building;
};

class Building {
public:
	friend void GoodDay::visit2();
	Building();
	string m_settingroom;
private:
	string bedroom;
};
Building ::Building(){
	bedroom = "Building's bedroom";
	m_settingroom = "Building's setting room";
}

GoodDay::GoodDay() {
	building = new Building;
}
void GoodDay::visit1() {
	cout << "GoodDay::visit1" << endl;
	cout << "Building's setting room: " << building->m_settingroom << endl;
	//cout << "Building's bedroom: " << building->bedroom << endl; // Accessing private member of Building
}
void GoodDay::visit2() {
		cout << "GoodDay::visit2" << endl;
		cout << "Building's setting room: " << building->m_settingroom << endl; // Accessing public member of Building
		cout << "Building's bedroom: " << building->bedroom << endl;
}
GoodDay::~GoodDay(){
	delete building;
	building = nullptr;
}
void test01() {//出错原因首先是把对象整成了指针，导致访问成员时需要使用->而不是.
	GoodDay gd;
	gd.visit1();
	gd.visit2();

}
int main() {
	test01();
	return 0;
}