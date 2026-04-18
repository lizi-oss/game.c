//指针与指针数组动态内存的使用
#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int* p = &a; //定义一个指针变量p，指向a的地址
	cout << "a的值为：" << a << endl; //输出a的值
	cout << "p指向的值为：" << *p << endl; //通过指针p访问a的值
	*p = 20; //通过指针p修改a的值
	cout << "修改后的a的值为：" << a << endl; //输出修改后的a的值
	
	int* arr = new int[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = i + 1; //给动态数组赋值
	}
	
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " "; //输出动态数组的元素
	}
	cout << endl;

	delete[] arr; //释放动态数组的内存

	return 0;
}