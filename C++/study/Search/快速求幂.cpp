#include<iostream>
using namespace std;
int Power(int x,int n){
    if(n==1){
        return x;
    }
    int pow=Power(x,n/2);
    pow=pow*pow;
    if(n%2==1){
        pow=pow*x;
    }
    return pow;
}
int main(){
    int a=10,n=3;
    int res=Power(a,n);
    cout<<res;
}