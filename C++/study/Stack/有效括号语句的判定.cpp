#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
bool isValid(string s){
    stack<char> stk;     //定义一个栈用来存储括号
    unordered_map<char,char> pairs={{')','('},{'}','{'},{']','['}};
        for(char ch:s){
            if(pairs.count(ch)){ //如果是右括号
                if(stk.empty()||stk.top()!=pairs[ch]){ //如果栈为空，或者栈顶括号不匹配，则返回false
                    return false;
                }
                //栈顶括号匹配则弹出栈顶
                stk.pop();
            }
            else{
                stk.push(ch); //如果是左括号，则压栈
            }
        }
        return stk.empty();   //遍历完后如果栈为空返回true，否则返回false
}
int main(){
    string s;
    cin>>s;
    if(isValid(s)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}