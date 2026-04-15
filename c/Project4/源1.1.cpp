#include <bits/stdc++.h>
using namespace std;

int n;
double a[200005];
long long t[200005];

// 判断：灯 x 是否被按奇数次
bool check(long long x) {
    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        // 注意浮点误差，+1e-12
        long long c1 = min(t[i], (long long)((x + 1) / a[i] + 1e-12));
        long long c0 = min(t[i], (long long)(x / a[i] + 1e-12));

        sum += (c1 - c0);
    }

    return sum % 2 == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> t[i];
    }

    long long l = 1, r = 1e18;

    while (l < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
    return 0;
}