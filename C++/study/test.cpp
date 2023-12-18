#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> a;
    int n, m, l, k;
    string b;
    cin>>n>>k;
    for (int i = 0; i < n; i++) {
      cin >> b >> l;
      if (l > k) //如果里程数大于k，则直接记录
        a[b] += l;
      else   //如果里程数小于k，则记录k
        a[b] += k;
    }
    cin>>m;
    for (int i = 0; i < m; i++) {
      cin >> b;
      if (a.count(b)) { //判断是否是会员
        cout << a[b] << endl;
      }
      else {
        cout << "No Info" << endl;
      }
    }
  
    return 0;
}
