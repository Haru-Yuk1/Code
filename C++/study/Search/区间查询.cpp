#include<iostream>
using namespace std;
int SearchinInterval(int arr[],int left,int right,int key){
    int low=left-1;
    int high=right+1;
    int mid;
    while(high>low+1){
        mid = (low + high)/2;	//取中间位置
		if(arr[mid] >= key){
			high = mid ;	
		}else{
			low = mid ;	//从后半部分继续查找
		}
	}
	return high;//或者 low;	// high :>=key的最小值位置 low:<key的最大值位置   
}
int main(){

}