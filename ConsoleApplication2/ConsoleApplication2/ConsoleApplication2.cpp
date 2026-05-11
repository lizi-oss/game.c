#include<iostream>
using namespace std;

//成员函数：属于类的函数，写在 class Cube { ... } 里面，用 对象.函数() 调用
//全局函数：不属于任何类，写在类外面，直接调用，也可以操作多个对象
int cube() {
	int a;
	cout << "全局函数：请输入边长：" << endl;
	cin >> a;
	cout << "面积：" << a * a << endl;
	cout << "体积：" << a * a * a << endl;
	return a;
}
class cube1 {
public:
	int a;
	
	int fanhui() {
		cout << "成员函数：请输入边长：";
		cin >> a;
		cout << "面积：" << a * a << endl;
		cout << "体积：" << a * a * a << endl;
		return a;
	}
};

int main() {
	cube1 c;
	int a=c.fanhui();
	int b = cube();
	if (a > b) {
		cout << "成员函数的值大于全局函数的值" << endl;
	}
	else if (a < b) {
		cout << "成员函数的值小于全局函数的值" << endl;
	}
	else {
		cout << "成员函数的值等于全局函数的值" << endl;
	}
	return 0;
}