#include <iostream>
using namespace std;

int main() {
  // 输入两个正整数，表示总人数和询问人数
  int N, M;
  cin >> N >> M;
  // 计算一等奖、二等奖和三等奖的人数，按1:3:6的比例
  int first = N / 10;
  int second = N / 10 * 3;
  int third = N / 10 * 6;
  // 循环M次，每次输入一个排名，输出对应的奖项级别
  for (int i = 0; i < M; i++) {
    int rank;
    cin >> rank;
    if (rank <= first) {
      cout << 1 << endl;
    } else if (rank <= first + second) {
      cout << 2 << endl;
    } else if (rank <= first + second + third) {
      cout << 3 << endl;
    } else {
      cout << "Invalid rank" << endl;
    }
  }
  return 0;
}
