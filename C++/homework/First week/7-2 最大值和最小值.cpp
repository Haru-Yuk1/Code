#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int max=0,min=0,x;

    for(int i=0;i<N;i++){
        cin>>x;
        
        if(max<x){
            max=x;
        }
        if(min>x){
            min=x;
        }
    }
    cout<<max-min;
}