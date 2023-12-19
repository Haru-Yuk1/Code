#include<iostream>
using namespace std;
int main(){
    int n,p;
    cin>>n>>p;
    int hashTable[p];
    for(int i=0;i<p;i++){
        hashTable[i]=-1;
    }
    for(int i=0;i<n;i++){
        int key;
        cin>>key;
        int index=key%p;
        while(hashTable[index]!=-1){
            index=(index+1)%p;
        }
        hashTable[index]=key;
        cout<<index<<" ";
    }
    
}