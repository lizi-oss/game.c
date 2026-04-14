#include<iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int a[1005];//构建数组
		bool vis[1005] = { false };//构建访问数组
		bool flag = true;//构建标志位

        for (int i = 0; i < n; i++) {
            cin >> a[i];//输入数组元素
        }

        if (n == 1) {
            cout << "Jolly" << endl;
			continue;//如果只有一个元素，直接输出Jolly，且退出整个程序进入下一轮。
        }

        for (int i = 0; i < n - 1; i++) {
			int d = abs(a[i] - a[i + 1]);//abs是绝对值的计算函数，计算相邻元素的差的绝对值

            if (d < 1 || d > n - 1) {
                flag = false;
				continue;//如果差的绝对值不在1到n-1之间，说明不是Jolly，设置标志位为false，并继续下一轮循环。最主要还是错在了这里，之前没有continue，导致数组越界。
            }
            vis[d] = true;
        }

        for (int i = 1; i <= n - 1; i++) {
            if (!vis[i]) {
                flag = false;
				break;//如果有任何一个差的绝对值没有出现，说明不是Jolly，设置标志位为false，并退出循环。
            }
        }

        if (flag)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}