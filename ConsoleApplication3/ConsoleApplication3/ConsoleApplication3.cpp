#include<iostream>
using namespace std;

//static变量的用法
//声明必须加 static
//类外定义时，不能再写 static 关键字
//静态成员函数没有 this 指针，所以不能直接访问非静态成员变量函数
class person {
public:
	static int m_Age;//静态成员变量，属于类，不属于对象，所有对象共享同一份数据
	const static int MAX_NUM = 100; // 可以类内直接初始化
	static void func() {
		//静态成员函数，属于类，不属于对象，所有对象共享同一份函数
		cout << "静态成员函数" << endl;
	}
private:
	int m_Id;//非静态成员变量，属于对象，每个对象有自己的数据
};
int person::m_Age = 0;//静态成员变量必须在类外初始化，且只能初始化一次

//int person::m_Id = 123456;//静态成员函数，属于类，不属于对象，所有对象共享同一份函数
void test01() {
	person p1;//创建第一个对象，静态成员变量m_Age被初始化为0
	cout << "p1.m_Age = " << p1.m_Age << endl;
	cout << "p1.MAX_NUM = " << p1.MAX_NUM << endl;
	p1.func();//通过对象访问静态成员函数，所有对象共享同一份函数，所以p2.func()也可以调用
	person::func();//通过类名访问静态成员函数，所有对象共享同一份函数，所以p1.func()也可以调用
	person p2;//创建第二个对象，静态成员变量仍然是0，因为所有对象共享同一份数据
	p1.m_Age = 10;//通过对象访问静态成员变量，所有对象共享同一份数据，所以p2.m_Age也变成了10
	//这里会报错：p1.MAX_NUM = 10;因为加上了const修饰，MAX_NUM是一个常量，不能被修改。
	cout << "p1.m_Age = " << p1.m_Age << endl;
	cout << "p2.m_Age = " << person::m_Age << endl;
	cout << "p1.MAX_NUM = " << p1.MAX_NUM << endl;
	//cout << "p1.m_Id = " << p1.m_Id << endl;//非静态成员变量不能通过对象访问，编译错误
}
int main() {
	test01();
	return 0;
}