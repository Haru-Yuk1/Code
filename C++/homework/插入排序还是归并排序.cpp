#include <iostream>
#include <algorithm>
using namespace std;
// 定义常量N作为数组的最大长度
const int N = 110;
// 定义两个数组，分别存储原始序列和中间序列
int a[N], s[N];
// 定义一个变量n，存储序列的长度
int n;

// 主函数，用于测试
int main() {
  // 输入序列的长度
  cin >> n;
  // 输入原始序列
  for (int i = 0; i < n; i++) 
  {  
    cin >> a[i];
  }
  // 输入中间序列
  for (int i = 0; i < n; i++)
  {
     cin >> s[i];
  }
  // 定义两个变量i和j，用于遍历序列
  int i, j;
  // 找到中间序列中第一个不满足升序的元素的位置
  for (i = 0; i < n - 1 && s[i] <= s[i + 1]; i++);
  // 检查中间序列的剩余部分是否和原始序列相同
  for (j = i + 1; j < n; j++) {
    if (a[j] != s[j]) break;
  }
  // 如果相同，说明使用的是插入排序
  if (j == n) {
    // 输出结果
    cout << "Insertion Sort" << endl;
    // 对原始序列中已经排好序的部分再插入一个元素
    sort(a, a + min(i + 2, n));
  }
  // 如果不同，说明使用的是归并排序
  else {
    // 输出结果
    cout << "Merge Sort" << endl;
    // 定义一个标志变量，表示是否找到了中间序列
    int flag = 1;
    // 定义一个步长变量，表示每次归并的子序列的长度
    int step = 1;
    // 循环直到找到中间序列
    while (flag) {
      // 假设已经找到中间序列
      flag = 0;
      // 遍历原始序列，判断是否和中间序列相同
      for (int k = 0; k < n; k++) {
        if (a[k] != s[k]) {
          // 如果不同，说明还没有找到中间序列，更新标志变量
          flag = 1;
        }
      }
      // 将步长翻倍，表示下一轮的归并
      step = step * 2;
      // 对原始序列进行归并排序
      for (int k = 0; k < n; k += step) {
        sort(a + k, a + min(k + step, n));
      }
    }
  }
  // 输出下一轮的结果序列
  for (int k = 0; k < n; k++) {
    if (k) cout << " " << a[k];
    else cout << a[k];
  }
  // 输出换行符
  cout << endl;
  // 返回0，表示程序正常结束
  return 0;
}
