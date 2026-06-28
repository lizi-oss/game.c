#include<iostream>
#include<string>
using namespace std;

class Animal {
public:
	virtual void speak() {
		cout << "Animal speaks" << endl;
	}
};
class Cat :public Animal {
public:
	void speak() {
		cout << "Meow" << endl;
	}
};
//执行说话的函数
void doSpeak(Animal &animal) {
	animal.speak();
	//这里执行cat是因为多态的特性，
	///*animal是一个Animal类型的引用，但是它引用的是一个Cat对象，
	//所以调用的是Cat类中的speak()方法。自动执行。Animal& animal = cat;*/
	//如果父类函数不加上virtual那么就不会这样。
}
void test01(){
	Cat cat;
	doSpeak(cat);
}

int main() {
	test01();
	return 0;
}