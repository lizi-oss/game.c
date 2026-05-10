#include<iostream>
using namespace std;
const double PI = 3.14;

class Circle {
public:
	//在这里写这个类的属性
	//半径
	int m_r;
	//行为，通俗一点就是写函数写明白这个封装到底要干嘛，就是和Java有一点点区别吧。
	//获取圆的周长
	double calculateZC()
	{
		return 2* PI* m_r;
	}
};

int main() {

	Circle c1;//调用时和JAVA差不多都是利用这里去进行类的调用。
	c1.m_r = 10;//给类中的属性下定义
	cout << "圆的周长为：" << c1.calculateZC()<< endl;//这里调用时
	
	//new创建类对象
	Circle* c2 = new Circle;
	c2->m_r = 20;//指针用->
	cout << c2->calculateZC() << endl;
	delete c2;
	c2 = nullptr;

	//new 数组对象
	Circle* arr = new Circle[3];
	arr[0].m_r = 5;
	cout << arr[0].calculateZC() << endl;
	//数组对象必须delete[]
	delete[]arr;
	arr = nullptr;
	 
	return 0;
}