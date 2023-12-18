#include <stdio.h>
typedef struct node//结构体定义
{
  int data;
  struct node *next;
}snode,*ptr;

ptr pre (ptr h,int x);

int main()
{
  ptr head,p;
  int x;
  head=creat();//构造链表，无需用户完成，细节不表
  scanf("%d",&x);
  p=pre(head,x);
  if(p==NULL)
    printf("None");
  else
    printf("%d",p->data);
  return 0;
}

/* 请在这里填写答案 */
// pre函数的功能是找到链表中第一个值等于x的结点的前驱结点，如果没有找到，返回NULL
ptr pre (ptr h,int x) {
    // 定义两个指针变量，p指向当前结点，q指向前驱结点
    ptr p, q;
    // 如果链表为空或者头结点就是值等于x的结点，返回NULL
    if (h == NULL || h->data == x) {
        return NULL;
    }
    // 初始化p和q
    p = h->next; // p指向第二个结点
    q = h; // q指向头结点
    // 遍历链表，直到找到值等于x的结点或者到达链表尾部
    while (p != NULL && p->data != x) {
        q = p; // q后移一位
        p = p->next; // p后移一位
    }
    // 如果找到了值等于x的结点，返回其前驱结点q
    if (p != NULL) {
        return q;
    }
    // 否则，返回NULL
    else {
        return NULL;
    }
}
