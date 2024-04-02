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
        if(key<node->val){//key的值小于当前节点的值，说明以key为值的节点在左子树，往左子树查找
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
TreeNode* InsertUnRecur(TreeNode* head,int key){
    TreeNode* cur =head;
    TreeNode* curParent=nullptr;
    //先查找
    while(cur&&cur->val!=key){  //当当前结点不为空，且当前节点值不为key，将节点下移
        curParent=cur;          //先记录当前节点
        if(cur->val>key){       //key的值小于当前节点的值，说明以key为值的节点在左子树，往左子树查找
            cur=cur->left;
        }
        else{
            cur=cur->right;
        }
    }
    if(cur==nullptr){ //如果该节点不存在
        cur=new TreeNode(key);  //建立新节点
        if(curParent==nullptr){ //如果father=null说明整棵树不存在
            head=cur;
        }
        else if(key<curParent->val){  //如果小于父亲节点的值，则插入到左子树
            curParent->left=cur;
        }
        else{  //如果大于父亲节点的值，则插入到右子树
            curParent->right=cur;
        }
    }
    return head;
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
            return bst->left;
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

TreeNode* RemovalUnRecur(TreeNode* head, int key) {
    TreeNode *cur = head, *curParent = nullptr;
    //先查找
    while (cur && cur->val != key) {    //当当前结点不为空，且当前节点值不为key，将节点下移
        curParent = cur;
        if (cur->val > key) {          //key的值小于当前节点的值，说明以key为值的节点在左子树，往左子树查找
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (!cur) {                         //如果这个节点为空，说明没有该节点，则直接返回
        return head;
    }
    if (!cur->left && !cur->right) {    //如果左右子树为空，则直接将这个节点删除
        cur = nullptr;
    } else if (!cur->right) {           //如果该节点右子树为空，左子树作为子树
        cur = cur->left;
    } else if (!cur->left) {            //如果该节点左子树为空，右子树作为子树
        cur = cur->right;
    } else {                            //如果该节点左右子树都不为空，则找后继节点
        TreeNode *successor = cur->right, *successorParent = cur;
        while (successor->left) {       //找到最左的子树
            successorParent = successor;
            successor = successor->left;
        }
        if (successorParent->val == cur->val) { //如果该节点的父节点等于该节点的值，说明右节点没有左节点，就是后继节点
            successorParent->right = successor->right;
        } else {                       //如果找到后继节点，继承它的右节点
            successorParent->left = successor->right;
        }
        //把这个后继节点拿出来，作为新的当前节点
        successor->right = cur->right;
        successor->left = cur->left;
        cur = successor;
    }
    if (!curParent) {   //如果当前节点的父节点为空，则直接返回当前结点
        return cur;
    } else {    //不为空，则重新接好
        if (curParent->left && curParent->left->val == key) {   
            curParent->left = cur;
        } else {
            curParent->right = cur;
        }
        return head;
    }       
}

void InOrderRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    InOrderRecur(head->left);
    cout<<head->val<<" ";
    InOrderRecur(head->right);
    
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
    cout<<"原来的树中序遍历"<<endl;
    TreeNode* p=head;
    InOrderRecur(p);
    cout<<endl;
    cout<<"——————删除——————"<<endl;
    RemovalRecur(head,3);
    RemovalUnRecur(head,4);
    cout<<"删除后的树的中序遍历"<<endl;
    p=head;
    InOrderRecur(p);
    cout<<endl;
    cout<<"——————插入——————"<<endl;
    InsertRecur(head,3);
    InsertUnRecur(head,4);
    cout<<"插入后的树的中序遍历"<<endl;
    p=head;
    InOrderRecur(p);
    
    cout<<endl;
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