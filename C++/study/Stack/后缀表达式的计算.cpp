#include<bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++)
        {
            string& token=tokens[i];
            if(token!="+"&&token!="-"&&token!="*"&&token!="/") {
                stk.push(atoi(token.c_str()));  //主要不知道string怎么转换为int
            }   
            else{
                int num2=stk.top();
                stk.pop();
                int num1=stk.top();
                stk.pop();
                switch (token[0])
                {
                case '+':
                    stk.push(num1+num2);
                    break;
                case '-':
                    stk.push(num1-num2);
                    break;
                case '*':
                    stk.push(num1*num2);
                    break;
                case '/':
                    stk.push(num1/num2);
                    break;
                }
            }        
        }
        return stk.top();
    }
int main(){
    string str;
    getline(cin,str);
    string s;
    stringstream ss(str);
    vector<string> tokens;

    while(getline(ss,s,' ')){
        tokens.push_back(s);
    }
    
    cout<<evalRPN(tokens);
}