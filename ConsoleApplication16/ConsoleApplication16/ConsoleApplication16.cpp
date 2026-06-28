#include<iostream>
#include<string>
using namespace std;

//类做友元
class Building;

class GoodDay
{
public:
	
	GoodDay();
	void visit();
	~GoodDay();
private://指针放在私有属性中封装效果更好。
	Building* building;
};

class Building {
	friend class GoodDay;
public:
	Building();
public:
	string m_sittinroom;
	string m_kitchen;
private:
	string m_bedroom;
	string m_bathroom;
};

Building::Building() {
	m_sittinroom = "客厅";
	m_kitchen = "厨房";
	m_bedroom = "卧室";
	m_bathroom = "卫生间";
}

GoodDay::GoodDay() {
	building = new Building;
}

GoodDay::~GoodDay() {
	delete building;
	building = nullptr;
}

void GoodDay::visit() {
	cout << "好基友正在访问：" << building->m_bathroom << endl;
	cout << "好基友正在访问：" << building->m_bedroom << endl;
	cout << "好基友正在访问：" << building->m_kitchen << endl;
	cout << "好基友正在访问：" << building->m_sittinroom << endl;
}

void test01() {
		GoodDay gd;
		gd.visit();
}
int main() {
	test01();

	system("pause");
	return 0;
}