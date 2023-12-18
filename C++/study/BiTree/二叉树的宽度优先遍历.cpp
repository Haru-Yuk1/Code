#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode():val(0),right(nullptr),left(nullptr){}
    TreeNode(int x):val(x),right(nullptr),left(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right ):val(x),left(left),right(right){}
};
void widthTraversal(TreeNode* head){
    if(head==nullptr){
        return;
    }
    queue<TreeNode*> q;
    q.push(head);
    while (!q.empty())
    {
        TreeNode* cur=q.back();
        q.pop();
        cout<<cur->val<<" ";
        if(cur->left!=nullptr){
            q.push(cur->left);
        }
        if(cur->right!=nullptr){
            q.push(cur->right);
        }
    }
    
}