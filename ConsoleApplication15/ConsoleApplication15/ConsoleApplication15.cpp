#include <iostream>
#include <string>
using namespace std;

class Building {
	//加上friend关键字后，goodGay全局函数就可以访问Building类中的私有成员
    //friend加载全局函数之前就可以。写在类的最上面就可以。
    friend void goodGay(Building* building);
public:
    Building() {
        m_bedroom = "卧室";
        m_stringroom = "客厅";
    }
public:
    string m_stringroom;//客厅
private:
    string m_bedroom;//卧室
};

//全局函数
void goodGay(Building* building) {
    cout << "好基友全局函数正在访问：" << building->m_stringroom << endl;
    building->m_bedroom = "超级无敌豪华大卧室，我的梦想，其实我的梦想挺简单的，就是一个很舒服的房子，赚足够的钱，我的父母不受劳累，我也不累家人也不累就可以。";
	cout << "好基友全局函数正在访问：" << building->m_bedroom << endl;
}

void test01() {
    Building building;
    goodGay(&building);
    Building building2;
    building2.m_stringroom = "卧室";
    goodGay(&building2);
}

int main()
{
    test01();
    return 0;
}
