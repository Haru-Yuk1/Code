#include <iostream>
#include <algorithm>
using namespace std;

// 二分查找函数，返回元素在数组中的位置，如果不存在则返回0
int binary_search(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) return mid + 1; // 位置从1开始
        else if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int main() {
    int n; // 输入的整数个数
    while (cin >> n) {
        int arr[n]; // 存储输入的整数
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n); // 对数组进行升序排序
        for (int i = 0; i < n; i++) {
            if(i==n-1){
                cout<<arr[i];
            }
            else{
                cout << arr[i] << " "; // 输出排序后的结果
            }
            
        }
        cout << endl;
        int m; // 查询次数
        cin >> m;
        for (int i = 0; i < m; i++) {
            int x; // 待查找的整数
            cin >> x;
            if(i==m-1){
                cout << binary_search(arr, n, x);
            }
            else{
                cout << binary_search(arr, n, x) << " "; // 输出查找的结果
            }
            
        }
        cout << endl;
    }
    return 0;
}
