#include<iostream>
using namespace std;
#define MaxSize 10
struct SeqList
{
    int Data[MaxSize];
    int length;
};

//顺序表的初始化
void InitList(SeqList *L,int newSize){
    L->Data=new int[newSize];
    L->length=MaxSize;
}
