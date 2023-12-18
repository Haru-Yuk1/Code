#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;
    int weight;
    TreeNode():val(0),right(nullptr),left(nullptr){}
    TreeNode(int x):val(x),right(nullptr),left(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right ):val(x),left(left),right(right){}
};
TreeNode* CreateHuffmanTree(vector<int> w){
    int n=w.size();
    unordered_set<TreeNode*> treeSet;
    for(int i=0;i<n;i++){
        TreeNode* node=new TreeNode();
        node->left=nullptr;
        node->right=nullptr;
        node->weight=w[i];
        treeSet.emplace(node);
    }
}