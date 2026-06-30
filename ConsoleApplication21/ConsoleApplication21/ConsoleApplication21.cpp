#include<iostream>
#include<string>
using namespace std;

class Remember{
public:
	virtual void eat(string name) {
		cout << "喜欢吃 " << name << endl;
	}
	virtual void drink() = 0;
};

class Son:public Remember {
public:
	void eat(string name) {
		cout << "咋不撑死你个神经病" << endl;
	}
	void drink(string name) {
		cout << "我要用" << name << "呛死你，我说实话我有点累了。" << endl;
		//子类必须重写纯虚函数，可以不写虚函数，但是必须写纯虚函数。知道吗？
	}
};
int main() {

	system("pause");
	return 0;
}