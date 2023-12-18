#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
bool compare(int o1,int o2){
    return o1-o2;
}
int lessMoney(vector<int> arr){
    priority_queue<int> pQ;
    for(int i=0;i<arr.size();i++){
        pQ.push(arr[i]);
    }
    int sum=0;
    int cur=0;
    while (pQ.size()>1)
    {
        cur=pQ.top();
        pQ.pop();
        cur+=pQ.top();
        pQ.pop();
        sum+=cur;
    }
    
}
int main(){

}