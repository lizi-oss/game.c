#include <iostream>
#include <vector>
using namespace std;

const int kMaxSize = 100;

class ArrNode {
public:
    vector<int> data_; // 存储数组
    int size_;         // 当前元素个数

    explicit ArrNode(int n)
        : data_(vector<int>(n)), size_(0) {
    }
};

// 插入函数
bool DecrSeqInsert(ArrNode& array, int x) {
    // 1. 判断是否已满
    if (array.size_ >= kMaxSize) {
        return false;
    }

    // 2. 找插入位置（递减序列）
    int pos = 0;
    while (pos < array.size_ && array.data_[pos] > x) {
        pos++;
    }

    // 3. 判断是否重复
    if (pos < array.size_&& array.data_[pos] == x) {
        return false;
    }

    // 4. 后移元素
    for (int i = array.size_; i > pos; i--) {
        array.data_[i] = array.data_[i - 1];
    }

    // 5. 插入
    array.data_[pos] = x;
    array.size_++;

    return true;
}

int main() {
    int n, x;
    cin >> n;

    ArrNode array(kMaxSize);
    array.size_ = n;

    for (int i = 0; i < n; i++) {
        cin >> array.data_[i];
    }

    cin >> x;

    if (!DecrSeqInsert(array, x)) {
        cout << "Insertion failed." << endl;
    }

    for (int i = 0; i < array.size_; i++) {
        if (i > 0) cout << " ";
        cout << array.data_[i];
    }

    cout << endl;
    cout << "Array size = " << array.size_ << endl;

    return 0;
}