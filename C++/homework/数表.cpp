#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
  int N;
  cin >> N; 
  int a[N]; 
  for (int i = 0; i < N; i++) {
    cin >> a[i]; 
  }
  vector<int> b; 
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
        b.push_back(a[i] + a[j]); 
        }
    }
    sort(b.begin(), b.end()); 
    for (int i = 0; i < b.size(); i++) {
        if(i==b.size()-1){
            cout<<b[i];
        }
        else{
            cout << b[i] << " "; 
        }
        
    }
    cout << endl; 
  return 0; 
}
