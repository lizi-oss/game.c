#include<iostream>
using namespace std;
class Person {
public:
	//构造函数没有返回值，不用写void函数名与类名相同
	//可以有参数可以发生重载，创建对象的时候，构造函数会自动调用且只调用一次
	Person() {
		cout << "Person的构造函数的调用" << endl;	
	}
	//析构函数进行清理的操作，没有返回值，不写void
	//函数名和类名相同，在名称前面加上~，不可以有参数，所以也不能发生重载
	//对象在销毁前执行，自动调用，而且只会调用一次
	~Person() {
		cout << "Person析构函数的调用" << endl;
	}

};
void test01() {
	Person p;
}
int main() {
	test01();
}