#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int count=1;
    while(n!=1){
        cout<<n<<" "; 
        if(n%2==0){
            n/=2;
        }
        else{
            n=n*3+1;
        }
        count++;   
    }
    cout<<1<<endl;
    cout<<"count = "<<count;
}