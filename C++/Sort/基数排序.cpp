// #include<iostream>
// #include<algorithm>
// #include<cmath>
// using namespace std;
// int maxbits(int arr[],int n){
//     int Max=arr[0];
//     for(int i=0;i<n;i++){
//         Max=max(Max,arr[i]);
//     }
//     int res=0;
//     while(Max!=0){
//         res++;
//         Max/=10;
//     }
//     return res;
// }
// int getDigit(int x,int d){
//     return ((x/((int)pow(10,d-1)))%10);
// }
// void radixSort(int arr[],int L,int R,int digit){
    
//     const int radix=10;
//     int i=0,j=0;
//     int *bucket=new int [R-L+1];
//     for(int d=1;d<=digit;d++){
        
//         int count[radix];
        
//         for(i=L;i<=R;i++){   //进桶，记录每个位的个数
//             j=getDigit(arr[i],d);
//             count[j]++;
            
//         }
//         for(i=1;i<radix;i++){  //处理成前缀和
//             count[i]=count[i]+count[i-1];
            
//         }
    
//         for(i=R;i>=L;i--){
//             j=getDigit(arr[i],d);
//             bucket[count[j]-1]=arr[i];
//             count[j]--;
            
//         }
        
//         for(i=L,j=0;i<=R;i++,j++){
//             arr[i]=bucket[j];
//             cout<<"2";
//         }
//     }
// }

// int main() {
//     int n; // 输入的整数个数
//     cin >> n; // 输入整数个数
//     int nums[n]; // 创建一个存储整数的向量
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i]; // 输入每个整数
//     }
//     int maxbit=maxbits(nums,n);
//     radixSort(nums,0,n-1,maxbit); // 对整数进行基数排序
//     for (int i=0;i<n;i++) {
//         cout << nums[i] << " "; // 输出排序后的整数
//     }
//     cout << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
using namespace std;

// 定义一个基数排序函数，参数为一个整数向量
void radix_sort(vector<int>& nums) {
    // 找出向量中的最大值
    int max_num = nums[0];
    for (int num : nums) {
        max_num = max(max_num, num);
    }
    // 计算最大值的位数
    int digits = 0;
    while (max_num > 0) {
        digits++;
        max_num /= 10;
    }
    // 创建一个存储0-9的队列数组
    vector<queue<int>> buckets(10);
    // 从低位到高位进行排序
    for (int i = 0; i < digits; i++) {
        // 遍历原向量，将每个元素按照当前位的数字放入对应的队列中
        for (int num : nums) {
            int digit = (num / (int)pow(10, i)) % 10; // 计算当前位的数字
            buckets[digit].push(num); // 将元素放入队列中
        }
        // 遍历队列数组，将每个队列中的元素依次放回原向量
        int index = 0;
        for (int j = 0; j < 10; j++) {
            while (!buckets[j].empty()) {
                nums[index++] = buckets[j].front(); // 取出队列首元素放入原向量
                buckets[j].pop(); // 弹出队列首元素
            }
        }
    }
}

int main() {
    int n; // 输入的整数个数
    cin >> n; // 输入整数个数
    vector<int> nums(n); // 创建一个存储整数的向量
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // 输入每个整数
    }
    radix_sort(nums); // 对整数进行基数排序
    for (int num : nums) {
        cout << num << " "; // 输出排序后的整数
    }
    cout << endl;
    return 0;
}
