#include <stdio.h>
#include<cstdlib>
#define MAXSIZE 20
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position last; /* 线性表的长度*/
};
List Delete( List &L, ElementType minD, ElementType maxD ); //函数声明不需要加引用符号
List ReadInput(){
   int num,i,temp;
   scanf("%d",&num);
   List L =(List )malloc(sizeof(struct LNode)); //需要动态分配内存空间给L
   for(i=0;i<num;i++){
    scanf("%d",&(L->Data[i])); //这里应该是i，不是num
    }
    L->last = num-1;
    return L; //需要返回L
}
void PrintList( List L ){
     for(int i=0;i<=L->last;i++){
          printf("%d ",L->Data[i]);
        }
}

int main()
{
    List L;
    ElementType minD, maxD;
    int i;
    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );
    return 0;
}

/* 你的代码将被嵌在这里 */
List Delete( List &L, ElementType minD, ElementType maxD ){
    int i,j=0; //需要定义i和j
    for(i=0;i<=L->last;i++){ //遍历L中的所有元素
        if(L->Data[i]>=minD && L->Data[i]<=maxD){ //如果元素不在区间内，就保留
            L->Data[j] = L->Data[i]; //将元素复制到新的位置
            j++; //更新新的位置
        }
    }
    L->last = j-1; //更新L的长度
    return L; //返回L
}
