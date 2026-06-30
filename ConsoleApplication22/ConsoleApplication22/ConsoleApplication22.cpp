#include <iostream>
#include<string>
using namespace std;

class Basement {
public:
    void guocheng() {
        cout << "无论做什么热饮，我们都需要有基本的步骤，煮水，冲泡，倒入杯中，加入辅料" << endl;
        zuoliao();
    }
    virtual void zuoliao() = 0;
};

class coffe:public Basement {
public:
    void zuoliao() {
        cout << "加入猫屎咖啡，嗯，很优雅" << endl;
    }
};
class tea :public Basement {
public:
    void zuoliao() {
        cout << "加入龙井毛尖，嗯，很有品，还有钱" << endl;
    }
};
void test01() {
    Basement* co = new coffe();
    co->guocheng();
    delete co;
    co = nullptr;
    Basement* t = new tea();
    t->guocheng();
    delete t;
    t = nullptr;
}

int main()
{
    test01();
    std::cout << "Hello World!\n";
    return 0;
}

