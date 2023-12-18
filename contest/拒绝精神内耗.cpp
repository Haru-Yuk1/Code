// #include<iostream>
// #include<unordered_map>
// #include<string>

// using namespace std;
// int main(){
//     int n,t,penalty=0,solved=0;
//     string c,s;
//     unordered_map<string,int> problems;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>t>>c>>s;
//         if(s=="AC"&&!problems.count(c)){
//             problems[c]=t;
//             solved++;
//             penalty+=t;
//         }
//         else if(s=="WA"&&!problems.count(c)){
//             problems[c]=1;
    
//         }
//         else if(s=="WA"&&problems.count(c)){
//             problems[c]++;
//         }

//     }
//     for(auto p:problems){
//         if(p.second!=1){
//             penalty+=(p.second-1)*20;
//         }
//     }
//     cout<<solved<<" "<<penalty<<endl;
//     return 0;
// }


#include <iostream>
#include <map>
using namespace std;

const int MAXN = 100 + 5; // 定义最大提交次数
int t[MAXN]; // 定义每次提交的分钟数
char c[MAXN]; // 定义每次提交的题目代号
string s[MAXN]; // 定义每次提交的结果
map<char, int> wrong; // 定义每个题目的错误提交数
map<char, bool> solved; // 定义每个题目是否已经通过

// 计算函数，求通过题数和罚时
void calculate(int n, int& num, int& penalty) {
    // 初始化通过题数和罚时
    num = 0;
    penalty = 0;
    // 遍历每次提交
    for (int i = 0; i < n; i++) {
        // 如果这次提交是正确的
        if (s[i] == "AC") {
            // 如果这个题目还没有通过
            if (!solved[c[i]]) {
                // 更新通过题数
                num++;
                // 更新罚时
                penalty += t[i] + wrong[c[i]] * 20;
                // 标记这个题目已经通过
                solved[c[i]] = true;
            }
        } else { // 如果这次提交是错误的
            // 如果这个题目还没有通过
            if (!solved[c[i]]) {
                // 更新错误提交数
                wrong[c[i]]++;
            }
        }
    }
}

int main() {
    // 读入 n
    int n;
    cin >> n;
    // 读入每次提交的记录
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> c[i] >> s[i];
    }
    // 定义通过题数和罚时
    int num, penalty;
    // 调用计算函数，求通过题数和罚时
    calculate(n, num, penalty);
    // 输出结果
    cout << num << " " << penalty << endl;
    return 0;
}