#include<bits/stdc++.h>
using namespace std;
bool isValid(string s){
    stack<char> stk;
    unordered_map<char,char> pairs={{')','('},{'}','{'},{']','['},{'>','<'}};
    for(auto ch:s){
        if(pairs.count(ch)){//右括号
            if(stk.empty()||stk.top()!=pairs[ch]){
                return false;
            }
            stk.pop();
        }
        else{//左括号
            if(!stk.empty()&&((ch=='('&&stk.top()=='<')||
            (ch=='['&&(stk.top()=='('||stk.top()=='<'))||
            (ch=='{'&&(stk.top()=='('||stk.top()=='<'||stk.top()=='[')))){
                return false;
            }
            stk.push(ch);
        }

    }
    return stk.empty();
}
int main(){
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        if(isValid(s)){
            cout<<"YES"<<endl;
        }  
        else{
            cout<<"NO"<<endl;
        }
    }
    
    
}