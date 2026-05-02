#include <iostream>
using namespace std;

void append(int arr[], int& len, int addSize)//&len就是类似于指针的东西，直接改变原有变量很神奇牛逼
{
    if (len + addSize > 10)
    {
        cout << "数组已满" << endl;
        return;
    }

    for (int i = 0; i < addSize; i++)
    {
        cin >> arr[len + i];
    }

    len += addSize;
}

// 冒泡排序
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[10];
    int len = 0;

    cout << "输入几个数：";
    int n;
    cin >> n;

    cout << "输入元素：" << endl;
    append(arr, len, n);

    bubbleSort(arr, len);

    cout << "排序后：" << endl;

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}