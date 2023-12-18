#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stack <int> stk;
    int top=0;
    int res=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!='+'&&s[i]!='-'&&s[i]!='/'&&s[i]!='*'&&s[i]!='#'){
            stk.push(s[i]-'0');
        }
        else if(i=='+'){
            top=stk.top();
            stk.pop();
            if(stk.empty()){
                cout<<"Expression Error:";
            }
            stk.push(top+stk.top());
            stk.pop();
        }
        else if (i=='-')
        {
            top=stk.top();
            stk.pop();
            res+=top;
        }
        else if(i=='*'){
            top=stk.top();
            stk.pop();
            res*=top;
        }
        else if(i=='/'){
            top=stk.top();
            stk.pop();
            res/=top;
        }
    }
}
  