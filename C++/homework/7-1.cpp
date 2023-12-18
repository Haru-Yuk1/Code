// #include<iostream>
// using namespace std;
// int gcd(int a,int b){
//     if(b==0){
//         return a;
//     }
//     else{
//         return gcd(b,a%b);
//     }
// }
// int main(){
//     int A,B,g,l;
//     cin>>A>>B;
//     g=gcd(A,B);
//     l=(A*B)/g;
//     cout<<g<<","<<l;

// }


// 引入输入输出流头文件
#include <iostream>
// 引入数学头文件
#include <cmath>
// 使用标准命名空间
using namespace std;

// 定义一个函数，用Stein算法求两个正整数的最大公约数
int gcd_stein(int a, int b) {
  // 如果a和b都是0，返回0
  if (a == 0 && b == 0) {
    return 0;
  }
  // 如果a或b是0，返回另一个数
  if (a == 0 || b == 0) {
    return a + b;
  }
  // 如果a和b都是偶数，返回2乘以它们除以2的最大公约数
  if (a % 2 == 0 && b % 2 == 0) {
    return 2 * gcd_stein(a / 2, b / 2);
  }
  // 如果a是偶数，b是奇数，返回a除以2和b的最大公约数
  if (a % 2 == 0 && b % 2 == 1) {
    return gcd_stein(a / 2, b);
  }
  // 如果a是奇数，b是偶数，返回a和b除以2的最大公约数
  if (a % 2 == 1 && b % 2 == 0) {
    return gcd_stein(a, b / 2);
  }
  // 如果a和b都是奇数，返回它们差的绝对值和较小的数的最大公约数
  if (a % 2 == 1 && b % 2 == 1) {
    return gcd_stein(abs(a - b), min(a, b));
  }
}

// 定义一个函数，用两个正整数的乘积除以它们的最大公约数求最小公倍数
int lcm(int a, int b) {
  // 如果a或b是0，返回0
  if (a == 0 || b == 0) {
    return 0;
  }
  // 否则，返回a乘以b除以它们的最大公约数
  else {
    return a * b / gcd_stein(a, b);
  }
}

// 主函数
int main() {
   // 输入两个正整数A和B
   int A, B;
   cin >> A >> B;

   // 输出它们的最大公约数和最小公倍数，用逗号分隔
   cout << gcd_stein(A, B) << "," << lcm(A, B) << endl;

   // 返回0表示程序正常结束
   return 0;
}
