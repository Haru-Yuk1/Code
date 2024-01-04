#include <iostream>
using namespace std;

// 定义一个函数，用辗转相除法求两个数的最大公约数
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

// 定义一个函数，用最大公约数求两个数的最小公倍数
int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int main() {
  // 计算23、11和8的最小公倍数
  int multiple = lcm(lcm(23, 11), 8);
  // 从1开始遍历年份，直到找到一个能被最小公倍数整除的年份
  int year = 1;
  while (year % multiple != 0) {
    year++;
  }
  // 输出结果，格式为 YYYY is a special year!
  cout << year << " is a special year!" << endl;
  return 0;
}
