#include<iostream>
using namespace std;
const int MAXSIZE=1000;
int main(){
    int n;
    cin>>n;
    int tree[1000];
    for(int i=1;i<=n;i++){
        cin>>tree[i];
    }
    int a,b;
    cin>>a>>b;
    if(tree[a]==0){
        cout<<"ERROR: T["<<a<<"] is NULL"<<endl;
        return 0; 
    }
    if(tree[b]==0){
        cout<<"ERROR: T["<<b<<"] is NULL"<<endl;
        return 0;
    }

    while(a!=b){
        if(a>b){
            a=a/2;
        }
        else if(b>a){
            b=b/2;
        }
            
    }
    
    cout<<a<<" "<<tree[a];
    return 0;
}