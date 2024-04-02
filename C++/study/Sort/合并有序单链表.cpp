#include<iostream>
using namespace std;
// 单向链表
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode() : val(0), next(NULL) {}  //类似构造函数
    ListNode(int x) : val(x), next(NULL) {}
};
//将list2中的所有结点归并至list1
ListNode* MergeTwoList(ListNode* list1,ListNode* list2){
    ListNode* p1=list1;
    ListNode* p2=list2;
    while(p2){  
        ListNode* pre=nullptr;
        while (p1&&p1->val<=p2->val)    //遍历list1,找到刚好小于等于p2值的结点
        {                               //此时pre刚好是小于等于p2值的结点，p1是下一结点
            pre=p1;
            p1=p1->next;
        }
        ListNode* tmp=p2;       //定义一个tmp存储p2
        p2=p2->next;            //将p2后移
        tmp->next=p1;           //让该节点指向p1
        if(pre==nullptr){       //pre为空说明p1为空,说明list1是空的
            list1=tmp;
        }
        else{
            pre->next=tmp;
        }
        p1=tmp;
        
    }
    return list1;
}

int main(){
    //12578 346910
    ListNode* node1=new ListNode(1);
    ListNode* node2=new ListNode(2);
    ListNode* node3=new ListNode(3);
    ListNode* node4=new ListNode(4);
    ListNode* node5=new ListNode(5);
    ListNode* node6=new ListNode(6);
    ListNode* node7=new ListNode(7);
    ListNode* node8=new ListNode(8);
    ListNode* node9=new ListNode(9);
    ListNode* node10=new ListNode(10);

    node1->next=node2;
    node2->next=node5;
    node5->next=node7;
    node7->next=node8;

    node3->next=node4;
    node4->next=node6;
    node6->next=node9;
    node9->next=node10;

    ListNode* result = MergeTwoList(node1,node3);
    while (result)
    {
        cout<<result->val<<" ";
        result=result->next;
    }
    
    
}