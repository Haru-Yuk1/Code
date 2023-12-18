#include<iostream>
using namespace std;
int n;
void swap(int* a,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void quickSort(int* a,int begin,int end)
{
    if(begin >= end) return;//当begin>=end，结束递归操作
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
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    key = R;//以相遇点作为分界点，递归操作
    quickSort(a,begin,key - 1);//递归
    quickSort(a,key + 1,end);
}


int main() {
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
  

    // 调用快速排序函数
    quickSort(arr, 0, n - 1);
    
    return 0;
}