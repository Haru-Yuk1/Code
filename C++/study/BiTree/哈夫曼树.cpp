#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode
{
    TreeNode* right;
    TreeNode* left;
    int weight;
    TreeNode():weight(0),right(nullptr),left(nullptr){}
    TreeNode(int x):weight(x),right(nullptr),left(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right ):weight(x),left(left),right(right){}
};
//重载堆的比较器,最小堆
struct  cmp
{
    bool operator()(TreeNode* a,TreeNode* b){
        return a->weight>b->weight; //可以>= 看情况
    }
};
TreeNode* CreateHuffmanTree(vector<int> w){
    int n=w.size();
    priority_queue<TreeNode*,vector<TreeNode*>,cmp> treeSet;
    //遍历数据集w并建立结点放入小根堆
    for(int i=0;i<n;i++){
        TreeNode* node=new TreeNode();
        node->weight=w[i];
        treeSet.emplace(node);
    }
    //每次从最小堆取出最小和次小，建一个新结点作为其父结点，其权重为和，然后放入堆
    for(int i=0;i<n-1;i++){
        TreeNode* node=new TreeNode();
        node->left=treeSet.top();
        treeSet.pop();
        node->right=treeSet.top();
        treeSet.pop();
        node->weight=node->left->weight+node->right->weight;
        treeSet.emplace(node);
    }
    return treeSet.top();
}
void PreorderRecur(TreeNode* head){
    if(head==nullptr){
        return ;
    }
    cout<<head->weight<<" ";
    PreorderRecur(head->left);
    PreorderRecur(head->right);
}
int main(){
    vector<int> weight={1,2,3,4,5};
    TreeNode* head= CreateHuffmanTree(weight);
    PreorderRecur(head);
}