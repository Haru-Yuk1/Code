/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode.cn/problems/partition-list/description/
 *
 * algorithms
 * Medium (64.34%)
 * Likes:    762
 * Dislikes: 0
 * Total Accepted:    239.5K
 * Total Submissions: 372.3K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
 * 
 * 你应当 保留 两个分区中每个节点的初始相对位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,4,3,2,5,2], x = 3
 * 输出：[1,2,2,4,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [2,1], x = 2
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 200] 内
 * -100 
 * -200 
 * 
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* SH=nullptr;
        ListNode* ST=nullptr;
        ListNode* MH=nullptr;
        ListNode* MT=nullptr;
        ListNode* next=nullptr;
        while (head)
        {
            next=head->next;
            head->next=nullptr;
            if(head->val<x){
                if(SH==nullptr){
                    SH=head;
                    ST=head;
                }
                else{
                    ST->next=head;
                    ST=head;
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
            head=next;
            
        }
        if(ST!=nullptr){
                ST->next=MH;
                
        }
        return SH!=nullptr?SH:MH;
    }
};
// @lc code=end

