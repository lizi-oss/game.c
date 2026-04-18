#include <iostream>
using namespace std;

// static 版：用静态变量存结果
int* getMax(int arr[], int len) {
    // static 变量：全局只有一份，程序结束才销毁
    static int max_val;
    max_val = arr[0];

    for (int i = 1; i < len; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // 返回 static 变量的地址
    return &max_val;
}

int main() {
    int arr[] = { 10, 30, 20, 50, 40 };
    int len = sizeof(arr) / sizeof(arr[0]);

    int* result = getMax(arr, len);
    cout << "最大值是：" << *result << endl;

    // 注意：static 变量不需要手动 delete，程序结束自动释放

    return 0;
}