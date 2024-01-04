#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int count=1;
    cout<<n<<" ";
    while(n!=1){
        
        if(n%2==0){
            n/=2;
        }
        else{
            n=n*3+1;
        }
        count++;  
        if(n==1){
            cout<<n;
        }
        else{
            cout<<n<<" "; 
        }
         
    }

    cout<<endl<<"count = "<<count;
}