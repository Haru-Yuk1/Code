#include<iostream>
using namespace std;
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode() : val(0), next(nullptr) {}  //类似构造函数
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// ListNode listPartition1(ListNode head,int pivot){
//     if(head==NULL){
//         return head;
//     }
//     ListNode cur=head;
//     int i=0;
//     while (cur!=nullptr)// 得到数组大小
//     {
//         i++;
//         cur=cur.next;
//     }
//     ListNode nodeArr[i];

//     cur=head;
//     for(int j=0;j!=i;j++){
//         nodeArr[j]=cur;
//         cur=cur.next;

//     }
//     arrPartition(nodeArr,pivot);
//     for(int j=1;j!=i;j++){
//         nodeArr[i-1].next=nodeArr[i];
//     }
//     nodeArr[i-1].next=nullptr;
//     return nodeArr[0];
// }
// void arrPartition(ListNode nodeArr[],int pivot){
//     int small=-1;
//     int big=sizeof(nodeArr)/sizeof(nodeArr[0]);
//     int index=0;
//     while (index!=big)
//     {
//         if(nodeArr[index].val<pivot){
//             swap(nodeArr,++small,index++);
//         }
//         else if(nodeArr[index].val==pivot){
//             index++;
//         }
//         else{
//             swap(nodeArr,--big,index);
//         }

//     }
    
// }
// void swap(ListNode nodeArr[],int a,int b){
//     ListNode tmp=nodeArr[a];
//     nodeArr[a]=nodeArr[b];
//     nodeArr[b]=tmp;
// }

// 将链表分成三份，分别为大于等于和小于
ListNode* listPartition2(ListNode* head,int pivot){
    ListNode* SH=nullptr;
    ListNode* ST=nullptr;//小于指针
    ListNode* EH=nullptr;
    ListNode* ET=nullptr;//等于指针
    ListNode* MH=nullptr;
    ListNode* MT=nullptr;//大于指针
    ListNode* next=nullptr;
    while (head) //移动head指针
    {
        next=head->next; //记录下一个节点
        head->next=nullptr; //将该节点取出
        if(head->val<pivot){
            if(SH==nullptr){  //如果小于则放进小于链表，
                SH=head;
                ST=head;
            }
            else{
                ST->next=head; //链表不空，尾指针后移
                ST=head;
            }
            
        }
        else if (head->val==pivot)
        {
            if(EH==nullptr){
                EH=head;
                ET=head;

            }
            else{
                ET->next=head;
                ET=head;
            }
        }
        else{
            if(MH==nullptr){
                MH=head;
                MT=head;

            }
            else{
                MT->next=head;
                MT=head;
            }
            
        }
        head=next;//下一个节点
        
    }
    if(ST!=nullptr){ //如果小于指针不为空，将尾结点指向等于的头
            ST->next=EH; 
            ET=ET==nullptr?ST:ET; //如果等于的尾结点为空，说明等于链表为空，则重新指向小于尾
    }
    if (ET!=nullptr){
            ET->next=MH; //如果等于尾节点不为空，则指向大于的头
    }
    return SH!=nullptr?SH:(EH!=nullptr?EH:MH);
        
}
int main(){
    ListNode *head=new ListNode(1);
    ListNode *node1=new ListNode(3);
    ListNode *node2=new ListNode(3);
    ListNode *node3=new ListNode(4);
    ListNode *node4=new ListNode(5);
    ListNode *node5=new ListNode(2);
    head->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    ListNode* newhead=listPartition2(head,3);
    while (newhead)
    {
        /* code */
        cout<<newhead->val;
        newhead=newhead->next;
    }
    
}