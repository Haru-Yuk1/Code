#include<iostream>
//不用vector
//#include<vector>
using namespace std;
#define width 6
#define height 4

void infect(int a[][width],int j,int i)
{
	if(j < 0||j >= width ||i < 0|| i >= height || a[i][j] != 1)
		return;
	a[i][j] = 2;
	infect(a,j - 1,i);
	infect(a,j + 1,i);
	infect(a,j,i - 1);
	infect(a,j,i + 1);
}

int countIslands(int a[][width])
{
	int num = 0;
	for(int i = 0;i < height;i++)
	{
		for(int j = 0;j < width;j++)
		{
			if(a[i][j] == 1)
			{
				num++;
				infect(a,j,i);
			}
		}
	}
	return num;
}

int main()
{
	int a[height][width] = {
		{0,0,1,0,1,0},
		{1,1,1,0,1,0},
		{1,0,0,1,0,0},
		{0,0,0,0,0,0}};
	cout<<countIslands(a);


	return 0;
}
