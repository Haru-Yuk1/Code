#include<iostream>
#include<vector>
using namespace std;
void swap(int* a,int* b){
    int* temp=a;
    a=b;
    b=temp;
}
//希尔排序
vector<int> ShellSort(vector<int> arr)
{
	int n=arr.size();
    int gap = n;
	while (gap>1)
	{
		//每次对gap折半操作
		gap = gap / 2;
		//单趟排序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tem = arr[end + gap];
			while (end >= 0)
			{
				if (tem < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tem;
		}
	}
    return arr;
}
int main(){
    vector<int> arr={1,3,5,4,2};
    arr=ShellSort(arr);
    for(auto res:arr){
        cout<<res;
    }
}