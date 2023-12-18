#include<iostream>
#include<stack>

using namespace std;
int main(){
    stack <int> stk;
    long long int n;
    cin>>n;
    long long int temp;
    long long int cost=0,income=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(i<n-1){
            cost+=temp;
        }
        
        if(stk.empty()){
            stk.push(temp);
            continue;
        }
        while (!stk.empty()&&stk.top()<temp)
        {
            stk.pop();
            income+=temp;
        }
    
    stk.push(temp);
    }
    if (!stk.empty()){
        stk.pop();
        while (!stk.empty())
        {
            income+=temp;
            stk.pop();

        }
        
    }
cout<<income-cost;
}