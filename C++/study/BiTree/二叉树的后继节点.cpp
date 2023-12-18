#include<iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode* parent;
    TreeNode():val(0),right(nullptr),left(nullptr){}
    TreeNode(int x):val(x),right(nullptr),left(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right ):val(x),left(left),right(right){}
};
TreeNode* getLeftMost(TreeNode* node){
    if(node==nullptr){
        return node;
    }
    while (node->left!=nullptr)
    {
        node=node->left;
    }
    return node;
}

TreeNode* getSuccessorNode(TreeNode* node){
    if(node==nullptr){
        return node;
    }
    if(node->right!=nullptr){
        return getLeftMost(node->right);
    }
    else{
        TreeNode* parent=node->parent;
        while (parent!=nullptr&&parent->left!=node)
        {
            /* code */
            node=parent;
            parent=node->parent;
        }
        return parent;
        
    }
}