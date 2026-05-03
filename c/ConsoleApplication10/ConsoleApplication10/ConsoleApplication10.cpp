//纯指针版
//#include<iostream>
//using namespace std;
//#include<string.h>
//
//void ptr(int *arr) {
//	*(arr + 1) = 100;
//}
//
//void ps(int*arr,int len) {
//	for (int i = 0;i < len;i++) {
//		for (int j = 0;j < len - 1 - i;j++) {
//			if (*(arr+j) > *(arr+j+1)){
//				int temp;
//				temp = *(arr+j);
//				*(arr+j) = *(arr+j+1);
//				*(arr+j+1) = temp;
//			}
//		}
//	}
//}
//
//int sum(int(*arr)[3], int row) {
//	int sum = 0;
//	for (int i = 0;i < row;i++) {
//		for (int j = 0;j < 3;j++) {
//			sum += *(*(arr+i) + j);
//		}
//	}
//	return sum;
//}
//
//void print(int* arr,int size) {
//	cout << "一维数组：";
//	for (int i = 0; i < size; i++) {
//		cout << *(arr + i) << " ";
//	}
//	cout << endl;
//}
//int main() {
//	int arr[5] = {0,3,5,6,7};
//	ptr(arr);
//	int size = sizeof(arr) / sizeof(int);
//	ps(arr, size);
//	print(arr, size);
//	int arr2[2][3] = { {1,2,3},{4,5,6} };
//	int sum1=sum(arr2, 2);
//	cout << "二维数组总和：" << sum1 << endl;
//
//	return 0;
//}


////c++语法糖版
//#include<iostream>
//using namespace std;
//
//// 语法糖：一维数组引用传参
//void ptr(int arr[]) {
//    arr[1] = 100;   // 下标语法糖，不用 *(arr+1)
//}
//
//// 语法糖：冒泡 直接下标
//void ps(int arr[], int len) {
//    for (int i = 0; i < len; i++) {
//        for (int j = 0; j < len - 1 - i; j++) {
//            if (arr[j] > arr[j + 1]) {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//// C++语法糖模板：任意行列二维数组都能接，不用写死列数
//template<int R, int C>
//int sum(int(&arr)[R][C])
//{
//    int total = 0;
//    for (int i = 0; i < R; i++)
//    {
//        for (int j = 0; j < C; j++)
//        {
//            total += arr[i][j];  // 纯语法糖，不用*(*...)
//        }
//    }
//    return total;
//}
//
//// 语法糖打印一维
//void print(int arr[], int size)
//{
//    cout << "一维数组：";
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    int arr[5] = { 0,3,5,6,7 };
//    ptr(arr);
//    int size = sizeof(arr) / sizeof(int);
//    ps(arr, size);
//    print(arr, size);
//
//    int arr2[2][3] = { {1,2,3},{4,5,6} };
//    int sum1 = sum(arr2);  // 语法糖：不用传行列，自动推导
//    cout << "二维数组总和：" << sum1 << endl;
//
//    return 0;
//}
#include<iostream>
using namespace std;

// 一维数组引用 &arr 语法糖
void ptr(int(&arr)[5])
{
    arr[1] = 100;   // 纯下标语法糖
}

// 冒泡：一维数组引用
void ps(int(&arr)[5], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
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

// 二维数组 &arr 引用语法糖
int sum(int(&arr)[2][3])
{
    int total = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            total += arr[i][j];
    return total;
}

// 打印：一维数组引用
void print(int(&arr)[5], int size)
{
    cout << "一维数组：";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = { 0,3,5,6,7 };
    ptr(arr);

    int size = sizeof(arr) / sizeof(int);
    ps(arr, size);
    print(arr, size);

    int arr2[2][3] = { {1,2,3},{4,5,6} };
    int sum1 = sum(arr2);
    cout << "二维数组总和：" << sum1 << endl;

    return 0;
}