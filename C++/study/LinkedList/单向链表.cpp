#include<iostream>
using namespace std;
// 单向链表
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode() : val(0), next(NULL) {}  //类似构造函数
    ListNode(int x) : val(x), next(NULL) {}
};

int main(){
    // ListNode *node1 = new ListNode;
    // ListNode *node2 = new ListNode();   // 初始化值为0
 	// ListNode *node3 = new ListNode(100); // 初始化值为100
    // node1->next=node2;
 	// cout<< node1->val<<endl;
 	// cout<< node2->val<<endl;
    // cout<< node3->val<<endl;
    // cout<<node1->next->val<<endl;
    ListNode *head=new ListNode();
    ListNode *p=head;
    for(int i=1;i<5;i++){
        ListNode *node=new ListNode(i);
        p->next=node;
        p=p->next;
    }
  
    p->next=nullptr;

    p=head;
    while (p)
    {
        /* code */
        cout<<p->val;
        p=p->next;
    }

    
    
    
    
    return 0;
}


