#include<iostream>
using namespace std;
//把i拆成i-1，其中三步，i-1到中，i到右，i-1到右
void func(int i,string start,string end,string other){
    if(i==1){    //base case
        cout<<"Move 1 from "<<start<<" to "<<end<<endl;
    }
    else{
        func(i-1,start,other,end);
        cout<<"Move "<<i<<" from "<<start<<" to "<<end<<endl;
        func(i-1,other,end,start);
    } 
    //如果要找移动次数，则定义一个全局变量res， 这里res++即可
}
void Hanoi(int n){
    if(n>0){
        func(n,"左","右","中");
    }
}

int main(){
    int n;
    cin>>n;
    Hanoi(n);
}