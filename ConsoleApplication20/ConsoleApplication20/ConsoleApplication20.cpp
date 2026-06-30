#include<iostream>
#include<string>
using namespace std;

class Calculator {
public:
	int m_num1;//操作数1
	int m_num2;//操作数2

	int getResult(string oper) {
		if (oper == "+") {
			return m_num1 + m_num2;
		}
		else if (oper == "-") {
			return m_num1 - m_num2;
		}
		else if (oper == "*") {
			return m_num1 * m_num2;
		}
		else if (oper == "/") {
			return m_num1 / m_num2;
		}
		else {
			cout << "输入的运算符有误" << endl;
		}
	}

};
void test01() {
	Calculator c;
	c.m_num1 = 10;
	c.m_num2 = 5;
	cout <<c.m_num1<<" + "<<c.m_num2<<" = " << c.getResult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << "=" << c.getResult("-") << endl;
	cout << c.m_num1 << "*" << c.m_num2 << "=" << c.getResult("*") << endl;
	cout << c.m_num1 << "/" << c.m_num2 << "=" << c.getResult("/") << endl;
}

//利用多态去实现计算器
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int m_num1;
	int m_num2;
};

class Add :public AbstractCalculator {
public:
	int getResult() {
		return m_num1 + m_num2;
	}
};

class Sub :public AbstractCalculator {
public:
	int getResult() {
		return m_num1 - m_num2;
	}
};

class Mul :public AbstractCalculator {
public:
	int getResult() {
		return m_num1 * m_num2;
	}
};

class Chu :public AbstractCalculator {
public:
	int getResult() {
		return m_num1 / m_num2;
	}
};
void test02() {
	AbstractCalculator* a = new Add;
	a->m_num1 = 10;
	a->m_num2 = 5;
	cout << a->m_num1 << "+" << a->m_num2 << "=" << a->getResult() << endl;
	delete a;
	a = nullptr;
	AbstractCalculator* b = new Sub;
	b->m_num1 = 10;
	b->m_num2 = 5;
	cout << b->m_num1 << "-" << b->m_num2 << "=" << b->getResult() << endl;
	delete b;
	b = nullptr;
	a = new Mul;
	a->m_num1 = 100;
	a->m_num2 = 5;
	cout << a->m_num1 << "*" << a->m_num2 << "=" << a->getResult() << endl;
	delete a;
	a = nullptr;
}


int main() {
	test01();
	test02();
	system("pause");
	return 0;
}

	