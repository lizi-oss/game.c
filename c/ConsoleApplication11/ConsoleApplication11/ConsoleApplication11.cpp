#include<iostream>
using namespace std;

int* func() {
	//在堆区创建该数据类型
	int* p = new int(10);//new返回的是该类型的指针,()指代的是存放一个元素
	return p;
}

void test01() {
	int* p = func();
	cout << *p << endl;
	delete p;
}//堆区数据的由程序员管理开辟，程序员管理释放。如果想释放堆区的数据，利用关键字delete

//在堆区利用new开辟数组
void test02() {
	int *arr=new int[10];//[]10这里代表的是有十个元素。
	for (int i = 0;i < 10;i++) {
		arr[i]=i+100;
	}
	for (int i = 0;i < 10;i++) {
		cout << arr[i] << endl;
	}
	delete[] arr;//释放数组的时候要记得加上这个[]
}

int main() {
	//new的基本语法
	test01();
	test02();
	return 0;
	}
