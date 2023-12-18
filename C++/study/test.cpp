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
      if (l > k)
        a[b] += l;
      else
        a[b] += k;
    }
    cin>>m;
    for (int i = 0; i < m; i++) {
      cin >> b;
      if (a.count(b)) {
        cout << a[b] << endl;
      }
      else {
        cout << "No Info" << endl;
      }
    }
  
    return 0;
}
