#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int weight;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):weight(x),left(nullptr),right(nullptr){}
};
struct cmp{
    bool operator()(TreeNode* a,TreeNode* b){
        return a->weight>b->weight;
    }
};
TreeNode* CreateHuffmanTree(vector<int> weight){
    priority_queue<TreeNode*,vector<TreeNode*>,cmp> pq;
    for(auto w:weight){
        TreeNode* node=new TreeNode(w);
        pq.emplace(node);
    }
    
    for(int i=0;i<weight.size()-1;i++){
        TreeNode* child1= pq.top();
        pq.pop();
        TreeNode* child2=pq.top();
        pq.pop();
        TreeNode* node=new TreeNode(child1->weight+child2->weight);
        node->left=child1;
        node->right=child2;
        pq.emplace(node);
    }
    return pq.top();

}

int sum=0;
void PreorderRecur(TreeNode* head,int level){
    if(head==nullptr){
        return;
    }
    if(head->left==nullptr&&head->right==nullptr){
        sum+=head->weight*level;
    }
    
    PreorderRecur(head->left,level+1);
    PreorderRecur(head->right,level+1);
}
int main(){
    int n;
    cin>>n;
    vector<int> weight(n);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    TreeNode* head=CreateHuffmanTree(weight);
    
    
    PreorderRecur(head,0);
    cout<<sum;
}