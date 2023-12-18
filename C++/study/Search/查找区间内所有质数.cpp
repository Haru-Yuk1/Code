#include <iostream>
#include <vector>
using namespace std;

// 用埃式筛选法查找正整数区间[1,n]内所有质数的函数
vector<int> eratosthenes(int n) {
  vector<int> primes; // 存储找到的素数
  vector<bool> is_prime(n + 1, true); // 标记每个数是否是素数，初始都为true
  is_prime[0] = is_prime[1] = false; // 0和1不是素数，标记为false
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) { // 如果i是素数，就把它加入到primes中
      primes.push_back(i);
      // 用i的倍数从i*i开始筛掉所有能被i整除的数，因为小于i*i的合数已经被更小的素数筛掉了
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return primes; // 返回素数的向量
}

int main() {
  // 输入n的值
  int n;
  cout << "请输入n的值：";
  cin >> n;
  // 调用eratosthenes函数，得到区间[1,n]内的所有素数
  vector<int> primes = eratosthenes(n);
  // 输出素数
  cout << "区间[1," << n << "]内的所有素数如下：" << endl;
  for (int p : primes) {
    cout << p << " ";
  }
  cout << endl;
  return 0;
}
