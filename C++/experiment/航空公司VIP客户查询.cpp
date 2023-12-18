#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main() {
  unordered_map<string, int> a;
  int n, m, l;
  string b;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      cin >> b >> l;
      if (l > m)
        a[b] += l;
      else
        a[b] += m;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> b;
      if (a.count(b)) {
        cout << a[b] << endl;
      }
      else {
        cout << "No Info" << endl;
      }
    }
  }
  return 0;
}
