#include<iostream>
#include<unordered_map>
using namespace std;
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode *rand;
    ListNode() : val(0), next(nullptr) {}  //类似构造函数
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* copyListWithRand1(ListNode* head){
    unordered_map<ListNode*,ListNode*> map;
    ListNode* cur=head;
    while (cur!=nullptr)
    {
        map.insert(cur,new ListNode(cur->val));
        cur=cur->next;
    }
    cur=head;
    while(cur !=nullptr){
        map[cur]->next=map[cur->next];
        map[cur]->rand=map[cur->rand];
        cur=cur->next;
    }
    return map[head];
    
}
int main(){
    ListNode* n1=new ListNode(1);
    ListNode* n2=new ListNode(2);
    ListNode* n3=new ListNode(3);
    n1->next=n2;
    n2->next=n3;
    n1->rand=n3;
    n2->rand=n1;
    ListNode* c1=copyListWithRand1(n1);
    cout<<c1->rand->val;
    cout<<c1->next->rand->val;
}