#include<iostream>
using namespace std;
void swap(int* a,int* b){
    int* temp=a;
    a=b;
    b=temp;
}
//将序列arr根据轴点拆分，并输出轴点在序列中的位置
int Partition(int arr[],int l,int r){
    int i=l;    //左指针
    int j=r-1;  //右指针
    int p=arr[r];//选择序列最后一个元素作为轴点
    while(true){
        while (arr[i]<p&&i<r) //找到i以右第一个大于等于轴点的元素
        {
            i=i+1;
        }
        while (arr[j]>p&&j>l)  //找到j以前第一个小于等于轴点的元素
        {
            j=j-1;
        }
        if(i>=j){   //如果i大于等于j，说明已经完成了拆分
            break;
        }
        //如果i小于j，将arr[i]与arr[j]交换,然后都往下一个位置移
        swap(arr[i],arr[j]);
        i=i+1;
        j=j-1;
        
    }
    //将轴点和坑位交换,此时就有左边<=arr[i]<=右边
    swap(arr[i],arr[r]);
    return i;
}
void QuickSort(int arr[],int l,int r){
    if(l<r){
        int i=Partition(arr,l,r);
        QuickSort(arr,l,i-1);
        QuickSort(arr,i+1,r);
    }
}
int main(){
    int arr[5]={1,3,2,5,4};
    QuickSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
}