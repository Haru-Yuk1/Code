#include<iostream>
#include<vector>
#include<string>
using namespace std;

void swap(string& str, int i, int j) {
	char c = str[i];
	str[i] = str[j];
	str[j] = c;
}


//str[i..]范围上，所有的字符，都可以在i位置上，后续都去尝试
//str[0..i-1]范围上，是之前做的选择
//把所有字符串形成的全排列加入到res中
void process(string& str, int i, vector<string>& res) {
	if (i == str.length()) {
		res.push_back(str);
		return;
	}
	vector<bool>visited(26, false);
	for (int j = i; j < str.length(); j++) {
		if (visited[str[j] - 'a'] == false) {
			swap(str, i, j);
			process(str, i + 1, res);
			swap(str, j, i);
			visited[str[j] - 'a'] = true;
		}
	}
}

vector<string> fullPermutation(string str) {
	vector<string>res;
	process(str, 0, res);
	return res;
}


int main(){
    string s="abc";
    vector<string>result= fullPermutation(s);
    for(auto res:result){
        cout<<res<<endl;
    }
}