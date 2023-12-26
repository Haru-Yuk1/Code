#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;
bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> pairs={{')','('},{']','['}};
        for(char ch:s){
            if(pairs.count(ch)){ //如果是右括号
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
    cin>>s;
    if(isValid(s)){
        cout<<"OK";
    }
    else{
        cout<<"Wrong";
    }
}