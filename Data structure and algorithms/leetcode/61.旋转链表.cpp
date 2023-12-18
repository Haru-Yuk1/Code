/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode.cn/problems/rotate-list/description/
 *
 * algorithms
 * Medium (41.34%)
 * Likes:    995
 * Dislikes: 0
 * Total Accepted:    338.1K
 * Total Submissions: 817.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[4,5,1,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [0,1,2], k = 4
 * 输出：[2,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 500] 内
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
 * 
 * 
 */
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
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* p=head;
        ListNode* p2=head;
        int length=0;
        while (p)
        {
            p=p->next;
            length++;
        }
        int move=length-k%length;
        p=head;
        while (p->next){
            p=p->next;
            
        }
        p->next=head;
        for(int i=0;i<move;i++){
            p2=p2->next;
            p=p->next;
        }
        p->next=nullptr;
        return p2;
    }
};
// @lc code=end
int main(){
    Solution solut;
    ListNode* head=new ListNode();
    ListNode* l1=new ListNode(1);
    
    ListNode* l1n1=new ListNode(2);
  
    ListNode* l1n2=new ListNode(3);
    ListNode* l1n3=new ListNode(4);

    l1->next=l1n1;
    l1n1->next=l1n2;
    l1n2->next=l1n3;
   
    head=solut.rotateRight(head,2);
    // while(head){
    //     cout<<head->val;
    //     head=head->next;
    // }
}