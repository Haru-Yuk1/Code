#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    queue<int> q;
    for(int k=1;k<=n;k++){
        q.push(k);
    }
    while(!q.empty()){
        for(int i=1;i<=m-1;i++){
            int data=q.front();
            q.pop();
            q.push(data);
        }
        int data=q.front();
        q.pop();
        cout<<data<<" ";

    }

}