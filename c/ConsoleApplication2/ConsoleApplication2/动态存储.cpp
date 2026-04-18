#include <iostream>
using namespace std;

// 动态内存版：用 new 分配堆内存
int* getMax(int arr[], int len) {
    // 先找最大值
    int max_val = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // 在堆上分配一块 int 空间，存最大值
    int* p_max = new int;
    *p_max = max_val;

    // 返回这块堆内存的地址
    return p_max;
}

int main() {
    int arr[] = { 10, 30, 20, 50, 40 };
    int len = sizeof(arr) / sizeof(arr[0]);

    int* result = getMax(arr, len);
    cout << "最大值是：" << *result << endl;

    // 关键！用完必须 delete，释放堆内存，避免内存泄漏
    delete result;

    return 0;
}