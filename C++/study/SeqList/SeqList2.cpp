#include<iostream>
using namespace std;
#define MaxSize 10
struct SeqList
{
    int *Data;
    int length;
};

//顺序表的初始化
void InitList(SeqList *L){
    L=new SeqList;
    L->Data=new int[MaxSize];
    L->length=0;
}
//顺序表的查找
int Search(SeqList* L,int x){
    int i=0;
    while(i<=L->length&&L->Data[i]!=x){
        i=i+1;
    }
    if(i>L->length){
        i=NULL;
    }
    return i;
}
//顺序表的插入
void Insert(SeqList* L,int i,int x){
    if(L->length==MaxSize){
        cout<<"表满"<<endl;
        return;
    }
    if(i<1||i>L->length+1){
        cout<<"插入位置不合法"<<endl;
        return;
    }
    for(int j=L->length-1;j>i-1;j--){
        L->Data[j+1]=L->Data[j];
    }
    L->Data[i-1]=x;
    L->length++;
}
//顺序表的删除
void Remove(SeqList* L,int i){
    if(i<1||i>L->length+1){
        cout<<"删除位置不合法"<<endl;
        return;
    }
    for(int j=i;j<L->length-1;j++){
        L->Data[j-1]=L->Data[j];
    }
    L->length--;
}
//顺序表的反转 删除+插入
void Reverse1(SeqList* L){
    int n=L->length;
    for(int i=1;i<n-1;i++){
        int data=L->Data[n-1];
        Remove(L,n);
        Insert(L,i,data);
    }
}
//顺序表的反转 顺序交换
void Reverse2(SeqList* L){
    int n=L->length;
    for(int i=1;i<n/2;i++){
        int j=n-i+1;
        int data=L->Data[i-1];
        L->Data[i-1]=L->Data[j-1];
        L->Data[j-1]=data;
    }
}