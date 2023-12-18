/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (53.61%)
 * Likes:    1802
 * Dislikes: 0
 * Total Accepted:    644.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,2,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 * 
 * 
 * 
 * 
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
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
};
// @lc code=end

