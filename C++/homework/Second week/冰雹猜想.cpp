#include<bits/stdc++.h>
using namespace std;

//不能理解为啥这样才算对
int main(){
    int n;
    cin>>n;
    int count=1;
    while(n!=1){
        cout<<n<<" "; 
        if(n%2==0){
            n/=2;
        }
        else{
            n=n*3+1;
        }
        count++;   
    }
    cout<<1<<endl;
    cout<<"count = "<<count;
}


// #include <iostream>
// using namespace std;

// int main()
// {
//     // 定义一个整数变量n，用来存储用户输入的数
//     int n;
//     // 定义一个整数变量count，用来记录变化的次数，初始为0
//     int count = 0;
//     // 提示用户输入一个大于1的整数
//     // 从标准输入读取用户输入的数，赋值给n
//     cin >> n;
//     // 输出n的初始值
//     cout << n << " ";
//     // 使用一个循环，直到n变为1为止
//     while (n != 1)
//     {
//         // 如果n是偶数，就除以2，否则就乘以3再加1
//         if (n % 2 == 0)
//         {
//             n = n / 2;
//         }
//         else
//         {
//             n = n * 3 + 1;
//         }
//         // 输出n的当前值
//         if(n==1){
//             cout<<n;
//         }else{
//             cout << n << " "; 
//         }
        
//         // 变化次数加1
//         count++;
//     }
//     // 输出换行符
//     cout << endl;
//     // 输出变化次数
//     cout << "count = " << count+1 
//     // 返回0，表示程序正常结束
//     return 0;
// }