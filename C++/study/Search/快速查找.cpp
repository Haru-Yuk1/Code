#include<iostream>
using namespace std;
void swap(int* a,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int Partition(int* a,int begin,int end)
{
    
    int L = begin,R = end,key = begin;//定义L,R,key下标
    while(L < R)
    {
        while(a[R] >= a[key] && L < R)//右边先走，右边大于等于key就一直走下去，否则停下来，加上判断L < R，防止越界
        {
            R--;
        }
        while(a[L] <= a[key] && L < R)//同理
        {
            L++; 
        }
        swap(&a[L],&a[R]);//都停下来后交换
    }
    swap(&a[key],&a[R]);//最后key值和相遇点交换
    return R;
}

int QuickSearch(int arr[],int left,int right, int k){
    if(left<right){
        int m=Partition(arr,left,right);
        if(m==k) return arr[m];
        if(m<k) {
            return QuickSearch(arr,m+1,right,k);
        }

        else{
            return QuickSearch(arr,left,m-1,k);
        }
    }
    return arr[left];
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=QuickSearch(arr,0,n-1,k-1);
    cout<<res;

}