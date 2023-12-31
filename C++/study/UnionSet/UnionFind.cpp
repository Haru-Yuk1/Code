#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

class UnionFindSet 
{
private:
	unordered_map<char,char> fatherMap;
	unordered_map<char,int> sizeMap;
public:
	 UnionFindSet(vector<char> data);//构造
	 char findHead(char cur);		//找集合的代表节点
	 bool isameset(char a,char b);	//判断是否是同一个集合
	 void Union(char a,char b);		//合并集合
};

UnionFindSet::UnionFindSet(vector<char> data)
{
	{
		 fatherMap.clear();
		 sizeMap.clear();
		 //将vector的元素各自形成一个集合
		 for(auto var:data)
		 {
			 fatherMap.insert(pair<char,char>(var,var));//单个father指向自己
			 //sizeMap[var] = 1;
			 sizeMap.insert(pair<char,int>(var,1));//单个长度是1
		 }
	 }
}
//递归版
//char UnionFindSet::findHead(char cur)
//{
//	char father = fatherMap[cur];	//找到当前节点的father
//	if(father != cur)				//father和当前节点不同表示当前节点不是代表节点，继续找
//	{
//		cur = father;
//		father = findHead(cur);		//递归放入father继续找
//	}
//	fatherMap[cur] = father;		//递归后father是代表节点，对每个子节点father节点都改为代表节点
//	return father;
//}


//非递归版
char UnionFindSet::findHead(char cur)
{
	stack<char> child;
	while(fatherMap[cur] != cur)
	{
		child.push(cur);		//将沿途非代表节点入栈
		cur = fatherMap[cur];	//将当前节点father变为当前节点继续判断
	}
	//运行至此处时，cur是代表节点
	while(!child.empty())
	{
		fatherMap[child.top()] = cur;	//将栈中的非代表节点的father指向代表节点，完成扁平化
		child.pop();					//出栈
	}
	return cur;
}

bool UnionFindSet::isameset(char a,char b)
{
	return findHead(a) == findHead(b);
}

void UnionFindSet::Union(char a,char b)
{
	//找出两个集合的代表节点
	char head1 = findHead(a);
	char head2 = findHead(b);

	if(head1 == NULL || head2 == NULL)//边界问题，空集合直接返回
		return;

	if(head1!=head2)				//不在同一集合时合并
	{
		//记录两个代表节点的长度
		int size1 = sizeMap[head1];
		int size2 = sizeMap[head2];
		//将短的接入长的中
		if(size1 <= size2)
		{
			fatherMap[head1] = head2;
			sizeMap[head2] = size1 + size2;
		}
		else
		{
			fatherMap[head2] = head1;
			sizeMap[head1] = size1 + size2;
		}
	}
}
int main()
{
	vector<char> temp;//={'A','B','C','D','E,'F'};
	temp.push_back('A');
	temp.push_back('B');
	temp.push_back('C');
	temp.push_back('D');
	temp.push_back('E');
	temp.push_back('F');
	temp.push_back('G');
	temp.push_back('H');
	UnionFindSet m(temp);
	m.Union('B','A');
	
	m.Union('C','B');

	m.Union('D','E');
	m.Union('B','D');
	return 0;
}
