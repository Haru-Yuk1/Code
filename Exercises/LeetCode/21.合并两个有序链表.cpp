/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.23%)
 * Likes:    3316
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
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
};
// @lc code=end
int main(){
    Solution solut;
    ListNode* head=new ListNode();
    ListNode* l1=new ListNode(2);
    ListNode* l2=new ListNode(3);
    ListNode* l1n1=new ListNode(4);
    ListNode* l2n1=new ListNode(6);
    ListNode* l1n2=new ListNode(5);
    ListNode* l2n2=new ListNode(7);
    l1->next=l1n1;
    l1n1->next=l1n2;
    l2->next=l2n1;
    l2n1->next=l2n2;
    head=solut.mergeTwoLists(l1,l2);
    while(head){
        cout<<head->val;
        head=head->next;
    }
}
