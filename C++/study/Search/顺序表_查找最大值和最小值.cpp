#include<iostream>
using namespace std;
int res1[2];
int* findmaxandmin1(int arr[],int n){
    int max=arr[0];
    int min=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i]) max=arr[i];
        if(min>arr[i]) min=arr[i];
    }
    
    res1[0]=max;
    res1[1]=min;
    return res1;
}
int res2[2];
int* findmaxandmin2(int arr[],int n){
    int max=arr[0];
    int min=arr[0];
    int k=n%2;//n是奇数，k从1开始，否则从0开始
    while (k<n)
    {
        if(arr[k]<arr[k+1]){
            if(min>arr[k]) min=arr[k];
            if(max<arr[k+1]) max=arr[k+1];
        }
        else{
            if(min>arr[k+1]) min=arr[k+1];
            if(max<arr[k]) max=arr[k];
        }
        k=k+2; //每次同时比较两个元素
    }
    res2[0]=max;
    res2[1]=min;
    return res2;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i;i<n;i++){
        cin>>arr[i];
    }
    int* r1=findmaxandmin1(arr,n);
    int* r2=findmaxandmin2(arr,n);
    cout<<"法一的结果：最大值"<<r1[0]<<" 最小值："<<r1[1]<<endl;
    cout<<"法二的结果：最大值"<<r2[0]<<" 最小值："<<r2[1]<<endl;
}