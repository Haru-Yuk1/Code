/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (55.81%)
 * Likes:    1665
 * Dislikes: 0
 * Total Accepted:    440.7K
 * Total Submissions: 789.7K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* rp=head;
        ListNode* lp=head;
        while (left>1)
        {
           lp=lp->next;
           left--;
        }
        while (right>2)
        {
           rp=rp->next;
           right--;
        }
        
        
        ListNode* pre =nullptr ;  // 定义 pre 指针，初始化为 nullptr；
        ListNode* cur = rp->next;  // 定义 cur 指针，指向头结点；
        //迭代反转，利用三个指针，当cur从头结点移动到尾结点停止
        while(cur!=lp) {
            ListNode* tmp = cur->next;  // 定义 temp 指针，指向 cur->next 节点
            cur->next = pre;
            // 后移 pre 和 cur 指针
            pre = cur;  
            cur = tmp;
        }
        rp->next=pre;
        return head;
        
    }
};
// @lc code=end

