#include<iostream>
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

TreeNode* SearchBSTRecur(TreeNode* bst,int key){
    if(bst==nullptr||bst->val==key){
        return bst;
    }
    if(key<bst->val){ //key的值小于根，往左子树查找
        return SearchBSTRecur(bst->left,key);
    }
    else{ //key的值大于根，往右子树查找
        return SearchBSTRecur(bst->right,key);
    }
}
TreeNode* SearchBSTUnRecur(TreeNode* bst,int key){
    TreeNode* node=bst;
    while (node!=nullptr && node->val!=key)
    {
        if(key<node->val){//key的值小于根，往左子树查找
            node=node->left;
        }
        else{//key的值大于根，往右子树查找
            node=node->right;
        }
    }
    return node;
    
}
TreeNode* InsertRecur(TreeNode* bst,int key){
    if(bst==nullptr){ // 如果当前节点不存在，则插入新的节点
        bst=new TreeNode(key);
    }
    else if(key<bst->val){ //key的值小于根，往左子树插
        bst->left=InsertRecur(bst->left,key);

    }
    else if(key>bst->val){ //key的值大于根，往右子树插
        bst->right=InsertRecur(bst->right,key);
    }
    return bst; //当key的值等于根，说明已经有该节点或者已经插入
}
TreeNode* InsertUnRecur(TreeNode* bst,int key){
    TreeNode* node =bst;
    TreeNode* father=nullptr;
    while(node!=nullptr&&node->val!=key){ //直到查找到有这个节点或者不存在为止
        father=node;  
        if(key<node->val){  //将node下移
            node=node->left;
        }
        else{
            node-node->right;
        }
    }
    if(node==nullptr){ //如果该节点不存在
        node=new TreeNode(key);  //建立新节点
        if(father==nullptr){ //如果father=null说明整棵树不存在
            bst=node;
        }
        else if(key<father->val){  //如果小于父亲节点的值，则插入到左子树
            father->left=node;
        }
        else{  //如果大于父亲节点的值，则插入到右子树
            father->right=node;
        }
    }
    return bst;
}
TreeNode* RemovalRecur(TreeNode* bst,int key){
    if(bst==nullptr){
        return bst;
    }
    if(bst->val>key){ //往左子树找
        bst->left=RemovalRecur(bst->left,key);
        return bst;
    }
    else if(bst->val<key){  //往右子树找
        bst->right=RemovalRecur(bst->right,key);
        return bst;
    }
    else{
        if(!bst->left&&!bst->right){ //左右都为空，把该节点删了，直接返回空
            return nullptr;
        }
        
        if(bst->left==nullptr){ //左子树为空，将右子树作为新子树，返回右子节点
            return bst->right;
        }
        else if(bst->right==nullptr){ //右子树为空，将左子树作为新子树，返回左子节点
            return bst->right;
        }
        //左右都有子树
        TreeNode* minRight=bst->right;
        while (minRight->left) //找后继节点
        {
            minRight=minRight->left;
        }
        bst->right=RemovalRecur(bst->right,minRight->val); //递归调用删除minRight
        //将minRight更新为新的根节点返回，相当于交换了根节点删除
        minRight->right=bst->right;
        minRight->left=bst->left;
        return minRight;
    }
   return bst;

}

TreeNode* RemovalUnRecur(TreeNode* root, int key) {
    TreeNode *cur = root, *curParent = nullptr;
    while (cur && cur->val != key) {
        curParent = cur;
        if (cur->val > key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (!cur) {
        return root;
    }
    if (!cur->left && !cur->right) {
        cur = nullptr;
    } else if (!cur->right) {
        cur = cur->left;
    } else if (!cur->left) {
        cur = cur->right;
    } else {
        TreeNode *successor = cur->right, *successorParent = cur;
        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }
        if (successorParent->val == cur->val) {
            successorParent->right = successor->right;
        } else {
            successorParent->left = successor->right;
        }
        successor->right = cur->right;
        successor->left = cur->left;
        cur = successor;
    }
    if (!curParent) {
        return cur;
    } else {
        if (curParent->left && curParent->left->val == key) {
            curParent->left = cur;
        } else {
            curParent->right = cur;
        }
        return root;
    }       
}



int main(){
    TreeNode* head=new TreeNode(6);
    TreeNode* temp1=new TreeNode(2);
    TreeNode* temp2=new TreeNode(8);
    TreeNode* temp3=new TreeNode(1);
    TreeNode* temp4=new TreeNode(4);
    TreeNode* temp5=new TreeNode(3);
    
    head->left=temp1;
    head->right=temp2;
    temp1->left=temp3;
    temp1->right=temp4;
    temp4->left=temp5;
    RemovalUnRecur(head,3);
    InsertRecur(head,3);
    cout<<"——————查找——————"<<endl;
    if(SearchBSTRecur(head,3)){
        cout<<"找到该节点,值为:"<<SearchBSTRecur(head,3)->val;
    }
    else{
        cout<<"没找到";
    }
    cout<<endl;
    if(SearchBSTUnRecur(head,3)){
        cout<<"找到该节点,值为:"<<SearchBSTUnRecur(head,3)->val;
    }
    else{
        cout<<"没找到";
    }

}