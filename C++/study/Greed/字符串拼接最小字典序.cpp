#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(string a, string b){
    return a+b<b+a;
}
string lowestString(vector<string> strs){
    if(&strs==NULL||strs.size()==0){
        return "";
    }
    sort(strs.begin(),strs.end(),compare);
    string res="";
    for(int i=0;i<strs.size();i++){
        
        res+=strs[i];
    }
    return res;
}
int main(){
    vector<string> strs1={"ba","ab","e","d","f"};
    cout<<lowestString(strs1);
}