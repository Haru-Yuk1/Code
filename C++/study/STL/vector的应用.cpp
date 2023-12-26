#include<iostream>
#include<vector>
using namespace std;
int main(){
   //创建vector容器
   vector<int> values;
   vector<int> a1(3);
   vector<int> a2{1,2,3};
   
   values[1]=1;
   cout<<values[1];
   
}