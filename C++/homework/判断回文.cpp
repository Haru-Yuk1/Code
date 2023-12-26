#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int i=0,count=0;
    for(;i<str.size()/2;i++){
        if(str[i]==str[str.size()-i-1]){
            count++;
            continue;
        }
        else{
            break;
        }
    }
    if(count==str.size()/2){
        cout<<str<<"是回文。";
    }
    else{
        cout<<str<<"不是回文。";
    }
}