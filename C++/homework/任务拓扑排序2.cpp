#include<iostream>
#include<algorithm>
#include<vector>
#include<queue> 
int mapp[101][101]; //图
int du[101];//初始值为0？ 
int n,e,cnt; 
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;//小顶堆
vector<int>g[101];
int tpsort()//关键！ 
{
	int num=0;
	for(int i=0;i<n;i++)//现先将所有度为0的点入队 
	{
		if(du[i]==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u=q.top();
		cout<<u<<" ";
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			du[v]--;
			if(du[v]==0)
				q.push(v);
		}
		g[u].clear();
		num++;
	 } 
	
	if(num!=n)
	cout<<"unworkable project";
}
int main()
{
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		du[b]++;
	}
	tpsort();
}
