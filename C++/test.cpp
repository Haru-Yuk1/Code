#include<bits/stdc++.h>
using namespace std;
bool isValid(string s){
    stack<char> stk;
    unordered_map<char,char> pairs={{')','('},{']','['},{'}','{'}};
    for(auto ch:s){
        if(pairs.count(ch)){
            if(stk.empty()||stk.top()!=pairs[ch]){
                return false;
            }
            stk.pop();
        }
        else{
            stk.push(ch);
        }
    }
    return stk.empty();
}

int main(){
    
    string s;

}