#include<iostream>
using namespace std;

void printAllFolds(int i,int N,bool down){
    if(i>N){
        return;
    }
    printAllFolds(i+1,N,true);
    if(down){
        cout<<"凹";
    }
    else{
        cout<<"凸";
    }
    printAllFolds(i+1,N,false);
}
int main(){
    int N;
    cin>>N;
    printAllFolds(1,N,true);
}