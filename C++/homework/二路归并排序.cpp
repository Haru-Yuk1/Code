#include <iostream>

using namespace std;


void merge(int arr[],int L,int M,int R,int n){
    int help[R-L+1];//辅助数组
    int i=0;//数组指针
    int p1=L;//左半数组指针
    int p2=M+1;//右半指针
    while(p1<=M && p2<=R){  //比较合并至辅助数组
        help[i++]=arr[p1]<=arr[p2]?arr[p1++]:arr[p2++];
    }
    while (p1<=M){
        help[i++]=arr[p1++];
    }
    while (p2<=R){
        help[i++]=arr[p2++];
    }
    for(i=0;i<R-L+1;i++){ //返回至原数组
        arr[L+i]=help[i];
        
    }
    
    for(i=0;i<n;i++){
        
        if(i==n-1){
            cout<<arr[i]<<endl;
        }
        else{
            cout<<arr[i]<<" ";
        }
    }
    
}
void mergeSort(int arr[],int L,int R,int n){
    if(arr==NULL||L==R){
        return;
    }
    int mid=L+((R-L)>>1);
    mergeSort(arr,L,mid,n); //左
    mergeSort(arr,mid+1,R,n);//右
    merge(arr,L,mid,R,n); //归并
    
    
   
}
int main(){
    int n;
    while (cin>>n)
    {
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1){
            cout<<arr[0];
        }
        mergeSort(arr,0,n-1,n);
    }
    
    
    
   
}