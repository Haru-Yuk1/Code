/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 *
 * https://leetcode.cn/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (58.51%)
 * Likes:    2667
 * Dislikes: 0
 * Total Accepted:    716.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 * 
 * 
 */
#include<iostream>
#include<vector>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* l=new ListNode(0);
            ListNode* p=l;
            while (list1!=nullptr&&list2!=nullptr)//写成且只要有一个走完结束,也可或，但要多循环几次，不如直接链接剩下的
            {
                if(list1->val<list2->val){
                    p->next=list1;
                    list1=list1->next;
                }
                else{
                    p->next=list2;
                    list2=list2->next;
                }
            p=p->next;
            }
            p->next=list1!=nullptr?list1:list2;//把剩下的接上
            return l->next;//l是虚拟头结点，要指向下一个才是真正头节点
            
        }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=nullptr;
        for(int i=0;i<lists.size();++i){ //用++i 是到n-1停 ,用i++也行，但要到n-1
            ans=mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }
};
// @lc code=end

