#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
// 单向链表
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode() : val(0), next(NULL) {}  //类似构造函数
    ListNode(int x) : val(x), next(NULL) {}
};
int main(){
    ListNode *head1=new ListNode();
    ListNode *head2=new ListNode(1);
    ListNode *p1=head1;
    ListNode *p2=head2;
    srand((unsigned)time(NULL));
    for(int i=1;i<10;i++){
        if(i!=rand()%10){
            ListNode *node1=new ListNode(i);
            p1->next=node1;
            p1=p1->next;
        }
        
    }
    p1->next=nullptr;
    for(int i=1;i<10;i++){
        if(i!=rand()%10){
            ListNode *node2=new ListNode(i);
            p2->next=node2;
            p2=p2->next;
        }
        
    }
    p2->next=nullptr;
    p1=head1;
    cout<<"第一个链表:";
    while (p1)
    {
        
        cout<<p1->val;
        p1=p1->next;
    }
    cout<<endl<<"第二个链表:";
    p2=head2;
    while (p2)
    {
        
        cout<<p2->val;
        p2=p2->next;
    }
    p1=head1;
    p2=head2;
    cout<<endl<<"两个链表公共部分:";
    while(p1!=nullptr && p2!=nullptr){
        if(p1->val==p2->val){
            cout<<p1->val;
            p1=p1->next;
            p2=p2->next;
        }
        if(p1->val<p2->val){
            p1=p1->next;
        }
        if(p1->val>p2->val){
            p2=p2->next;
        }
        
    }
}