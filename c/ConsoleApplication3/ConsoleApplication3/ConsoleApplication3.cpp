#include <iostream>
using namespace std;
#include"Swap.h"

int main()
{
    int a = 100, b = 520;
    cout << "交换前a=" << a << "b=" << b << endl;
    swap(&a, &b);
    cout << "交换后a=" << a << "b=" << b << endl;
    std::cout << "Hello World!\n";
}

