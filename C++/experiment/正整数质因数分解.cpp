#include <iostream>
#include <cmath>
#include<vector>
using namespace std;

// 判断一个数是否是质数
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 输出一个数的所有质因数
vector<int> prime_factors(int n) {
    vector<int> arr;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && is_prime(i)) {
           arr.push_back(i);
        }
    }
    return arr;
}

int main() {
    int a;
    cin >> a;
    vector<int> res;
    res=prime_factors(a);
    for(int i=0;i<res.size();i++){
        if(i==res.size()-1){
            cout<<res[i];
        }
        else{
            cout<<res[i]<<" ";
        }    
    }
    return 0;
}
