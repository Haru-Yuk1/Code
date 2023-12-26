#include <iostream>
#include <queue>
#define MAX 105
using namespace std;

int map[MAX][MAX];
int in[MAX];	//in[i] = j表示结点i的入度数 = j 

int main()
{
	int N, k, x, num = 0;
	cin>>N;
	queue<int> Q;	//入度为0的结点队列 
	for(int i = 1;i <= N;i++)
	{
		cin>>k;
		if(!k) Q.push(i);	//入度为0，入队 
		while(k--)
		{
			cin>>x;
			map[x][i] = 1;
			in[i]++;		//入度数+1 
		}
	}
	while(!Q.empty())
	{
		int t = Q.front();	//记录出队结点 
		Q.pop();
		num++; 
		for(int i = 1;i <= N;i++)	//找t的出度结点(也就是i的入度结点)
		{
			if(map[t][i])	 
			{
				in[i]--;	//i的入度数-1 
				if(!in[i]) Q.push(i);	//若i入度为0，入队 
			}
		}
	}
	if(num != N) cout<<0<<endl;		//若存在环，num必定小于N，因为成环的结点入度数不会为0，不会入队。 
	else cout<<1<<endl;
	return 0;
}
