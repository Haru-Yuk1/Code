/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (46.35%)
 * Likes:    2707
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1], n = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * 
 * 进阶：你能尝试使用一趟扫描实现吗？
 * 
 */
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead= new ListNode(0);
        dummyHead->next=head;//虚拟头节点
        ListNode* p1=dummyHead;
        ListNode* p2=dummyHead;
        while (p2&&n--)
        {
            p2=p2->next;
        }
        p2=p2->next;
        while (p2)
        {
            p1=p1->next;
            p2=p2->next;
        }
        
        
        p1->next=p1->next->next;

    
        return dummyHead->next;//此处不能head，因为如果只有1个节点，则会返回空，而不是原来的head
    }
};
// @lc code=end

int main(){
    ListNode* head=new ListNode(1);
    ListNode* p=head;
    for(int i=1;i<5;i++){
        ListNode* node=new ListNode(i);
        p->next=node;
        p=p->next;
    
    }
    p=head;
    Solution solut;
    ListNode*p2=solut.removeNthFromEnd(head,1);
    while(p2){
        cout<<p2->val;
        p2=p2->next;
    }
}