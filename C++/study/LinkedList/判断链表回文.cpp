#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode() : val(0), next(nullptr) {}  //类似构造函数
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 法一,利用一个栈 o(n)
bool isPalindrome1(ListNode *head){
    
    stack<ListNode*> stk;
    ListNode *cur=head;
    //将链表结点压栈
    while (cur)
    {
        stk.push(cur);
        cur=cur->next;
    }
    //出栈与链表比对
    while (head)
    {
        if(head->val!=stk.top()->val){
            return false;
        }
        stk.pop();
        head=head->next;
    }
    return true;
}
//法二，利用栈+快慢指针 O(n/2)
bool isPalindrome2(ListNode* head){
    if(head->next==NULL){
        return true;
    }
    stack<ListNode*> stk;
    //使用双指针
    ListNode* right=head->next;
    ListNode* cur=head;
    // cur走两步,right 走到中点
    while (cur->next!=nullptr && cur->next->next !=nullptr)
    {
        right=right->next;
        
        cur=cur->next->next;
    }
    //将剩下的压入栈
    while (right)
    {
        stk.push(right);
        
        right=right->next;
    }
    //比对前半与后半
    while (!stk.empty())
    {
        
        if(head->val!=stk.top()->val){
            return false;
        }
        stk.pop();
        head=head->next;
    }
    return true;
}
//法三：利用快慢指针 O(1)
bool isPalindrome3(ListNode* head){
    if(head->next==NULL){
        return true;
    }
    ListNode* p1=head;
    ListNode* p2=head;
    // p1走到中间，p2走到最后
    while (p2->next!=nullptr && p2->next->next!=nullptr)
    {
        p1=p1->next;
        p2=p2->next->next;
    }
    p2=p1->next; 
    p1->next=nullptr; //将中间指向null
    ListNode* p3=nullptr;
    //将后半部分逆序
    while (p2!=nullptr)
    {
        p3=p2->next;//记录下一个
        p2->next=p1;//将指针反转
        //两个指针往后移
        p1=p2;
        p2=p3;
    }
    //将p3指向后半部分的头，p2指向前半部分的头进行比对
    p3=p1;
    p2=head;
    bool res=true;
    while (p1!=nullptr && p2!=nullptr)
    {
        if(p1->val!=p2->val){
            res=false;
            break;
        }
        p1=p1->next;
        p2=p2->next;

    }
    p1=p3->next;
    p3->next=nullptr;
    while (p1!=nullptr)//将后半部分逆序回来
    {
        p2=p1->next;
        p1->next=p3;
        p3=p1;
        p1=p2;
    }
    return res;
}


int main(){
    ListNode *head=new ListNode(1);
    ListNode *node1=new ListNode(3);
    ListNode *node2=new ListNode(3);
    ListNode *node3=new ListNode(2);
    head->next=node1;
    node1->next=node2;
    node2->next=node3;
    if(isPalindrome1(head)){
        cout<<"是回文"<<endl;
    }
    else{
        cout<<"不是回文"<<endl;
    }
    if(isPalindrome2(head)){
        cout<<"是回文"<<endl;
    }
    else{
        cout<<"不是回文"<<endl;
    }
    if(isPalindrome3(head)){
        cout<<"是回文"<<endl;
    }
    else{
        cout<<"不是回文"<<endl;
    }
}