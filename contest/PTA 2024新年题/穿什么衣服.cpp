#include <iostream>
using namespace std;

int main() {
  // 输入一个整数，表示温度
  int C;
  cin >> C;
  // 判断温度的范围，并输出相应的结果
  if (C >= 15 && C < 30) {
    cout << C << " Mama" << endl;
  } else if (C >= -10 && C < 15) {
    cout << C << " YuRongFu" << endl;
  } else if (C >= -100 && C < -10) {
    cout << C << " Zhai" << endl;
  } else {
    cout << "Invalid temperature" << endl;
  }
  return 0;
}
