#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i]<b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(b[i]==a[i]){
            count++;
            continue;
        }
        else{
            break;
        }
    }
    if(count==n){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}