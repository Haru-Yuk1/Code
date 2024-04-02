#include<iostream>
using namespace std;
//low和high实指
int BinarySearch1(int arr[],int left,int right,int key){
    int low=left;
    int high=right;
    int mid;
    while(low<=high){
        mid = (low + high)/2;	//取中间位置
		if(arr[mid] == key){
			return mid;	//查找成功返回所在位置
		}else if(arr[mid] > key){
			high = mid - 1;	//从前半部分继续查找
		}else{
			low = mid + 1;	//从后半部分继续查找
		}
	}
	return -1;	//查找失败，返回-1
}
//low和high虚指,在区间外
int BinarySearch2(int arr[],int left,int right,int key){
    int low=left-1;
    int high=right+1;
    int mid;
    while(high>low+1){
        mid = (low + high)/2;	//取中间位置
		if(arr[mid] == key){
			return mid;	//查找成功返回所在位置
		}else if(arr[mid] > key){
			high = mid ;	//从前半部分继续查找
		}else{
			low = mid ;	//从后半部分继续查找
		}
	}
	return -1;	//查找失败，返回-1    
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res1=BinarySearch1(arr,0,n-1,k);
    int res2=BinarySearch2(arr,0,n-1,k);
    cout<<res1<<" "<<res2;
}