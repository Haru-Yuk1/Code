#include<iostream>
using namespace std;

//交换函数
void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
// 大根堆的heapify
void maxHeapify(int arr[],int index,int heapsize)
{
	int left = 2*index+1; //左子树
	while (left < heapsize) 
	{
		int largest = left+1<heapsize && arr[left+1]>arr[left]? 
            left+1:left; //从根，左子树，右子树中选择最大的
		largest = arr[index] < arr[largest]?largest:index;
		if(index == largest)
			break;
		swap(arr[index],arr[largest]);
		index = largest;
		left = 2*index+1;
	}

}
//建立大根堆
void BuildMaxHeap(int arr[],int N){
    for(int i=N/2-1;i>=0;i--){ //自底向上
        maxHeapify(arr,i,N);
    }
}
//小根堆的heapify
void minHeapify(int arr[],int index,int heapsize)
{
	int left = 2*index+1;
	while (left < heapsize) 
	{
		int least = left+1<heapsize && arr[left+1]<arr[left]?
			left+1:left;//从根，左子树，右子树中选择最小的
		least = arr[index] > arr[least]?least:index;
		if(index == least)
			break;
		swap(arr[index],arr[least]);
		index = least;
		left = 2*index+1;
	}

}
//建立小根堆
void BuildMinHeap(int arr[],int N){
    for(int i=N/2-1;i>=0;i--){ //自底向上
        minHeapify(arr,i,N);
    }
}
int main(){
    int N;
    cin>>N;
    int arr1[N],arr2[N];
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        arr1[i]=x;
        arr2[i]=x;
    }
    BuildMaxHeap(arr1,N);
    for(int i=0;i<N;i++){
        if(i==N-1){
            cout<<arr1[i];
        }
        else{
            cout<<arr1[i]<<" ";
        }
        
    }
    cout<<endl;
    BuildMinHeap(arr2,N);
    for(int i=0;i<N;i++){
        
        if(i==N-1){
            cout<<arr2[i];
        }
        else{
            cout<<arr2[i]<<" ";
        }
    }
}