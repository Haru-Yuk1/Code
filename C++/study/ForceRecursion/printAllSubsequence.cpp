#include<iostream>
#include<string>
using namespace std;

//s是给定的字符串，i是索引，res是结果
void print(const string s,int i,string res)
{
	if(i == s.size())	//超出索引，打印上一级传递的结果
	{
        if(res.empty()){
            cout<<"空"<<endl;
            return;
        }
		cout<<res<<endl;
		return;
	}
	else
	{
		print(s,i + 1,res + s[i]);	//添加当前字符
		print(s,i + 1,res );		//丢弃当前字符
	}
}

int main()
{
	string s = "abc";
	string res;
	print(s,0,res);

	return 0;
}
