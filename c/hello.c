#include<iostream>
using namespace std;
int main() {
    int money = 300;
    int cunchu = 0;
    int yue = 0;
    for (int month = 1;month <= 12;month++) {
        int yusuan;
        cin >> yusuan;
        int total = yue + money;
        if (total < yusuan) {
            cout << -month << endl;
            return 0;
        }
        if (total - yusuan >= 100) {
            cunchu = (total - yusuan) / 100 * 100 + cunchu;
            yue = total - yusuan - (total - yusuan) / 100 * 100;
        }
        else {
            yue = total - yusuan;
        }
    }

    cout << cunchu * 1.2 + yue << endl;
    return 0;

}