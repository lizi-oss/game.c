#include<iostream>
using namespace std;

//单个 new → 对应 delete
//数组 new[] → 对应 delete[]
//指针访问成员用->，普通对象用 .
//new 必须手动 delete 释放内存
int main() {
	//new基础单个变量
	//堆上开辟int
	int* p = new int;
	*p = 100;
	cout << *p << endl;
	//释放
	delete p;
	p = nullptr;

	//new 变量并直接初始化
	int* p2 = new int(200);
	cout << *p2 << endl;
	delete p2;
	p2 = nullptr;

	//new 数组+delete[]
	int* arr = new int[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = i + 1;
		cout << arr[i] << endl;
	}
	//数组必须delete[]
	delete[] arr;
	arr = nullptr;
	
	//new

	return 0;
}