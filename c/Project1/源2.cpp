#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    bool has_ans = false;

    for (int i = 10000; i <= 30000; ++i) {

        int sub1 = i / 100;        // 前三位 a1a2a3
        int sub2 = i / 10 % 1000;  // 中间三位 a2a3a4
        int sub3 = i % 1000;       // 后三位 a3a4a5

        if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0) {
            cout << i << endl;
            has_ans = true;
        }
    }

    if (!has_ans) {
        cout << "No" << endl;
    }

    return 0;
}