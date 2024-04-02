#include<iostream>
using namespace std;
/*有哨兵顺序查找*/
int Sequential_Search(int *a, int n, int key){
	int i;
	a[0] = key;	//设置a[0]为关键字，称之为“哨兵”
	i = n;	//循环从数组尾部开始
	while(a[i] != key){
		i--;
	}
	return i;	//返回0则说明查找失败
}
int main(){

}