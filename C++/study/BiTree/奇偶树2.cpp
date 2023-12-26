#include<iostream>
#include<queue>
#include<vector>
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
//利用层序遍历
bool isParityTree1(TreeNode* head){
    queue<TreeNode*>node_queue; //结点队列
    queue<int>level_queue; //结点所在层数队列
    node_queue.push(head);
    level_queue.push(1);
    TreeNode* pre_node=nullptr; //记录前一个出队的非空结点
    int pre_level=0;//记录前一个出队的非空结点层数，初始值为0
    while(!node_queue.empty()){
        TreeNode* node_ptr=node_queue.front();
        node_queue.pop();
        int level=level_queue.front();
        level_queue.pop();
        if(node_ptr!=nullptr){
            if(node_ptr->val%2!=level%2){// 判断奇偶性是否相同
                return false;
            }
            else if(pre_level==level&&pre_node->val>=node_ptr->val){//判断是否递增
                return false;
            }
            pre_level=level;
            pre_node=node_ptr;
            node_queue.push(node_ptr->left); //压入左孩子
            level_queue.push(level+1);      //记录左孩子的层数
            node_queue.push(node_ptr->right);//压入右孩子
            level_queue.push(level+1); //记录右孩子的层数
        }
    }
    return true;
}
//利用前序遍历
vector<TreeNode*> pre_nodes(20);
bool isParityTree2(TreeNode* head,int level){
    if(head==nullptr){
        return true;
    }
    if(head->val%2!=level%2){
        return false;
    }
    if(pre_nodes[level]!=nullptr&&pre_nodes[level]->val>=head->val){
        return false;
    }
    pre_nodes[level]=head;//记录一层最先遇到的结点
    
    return isParityTree2(head->left,level+1)&&isParityTree2(head->right,level+1);

}
int main(){
    TreeNode* head=new TreeNode(3);
    TreeNode* temp1=new TreeNode(4);
    TreeNode* temp2=new TreeNode(6);
    TreeNode* temp3=new TreeNode(1);
    TreeNode* temp4=new TreeNode(5);
    TreeNode* temp5=new TreeNode(6);
    TreeNode* temp6=new TreeNode(9);
    TreeNode* temp7=new TreeNode(8);
    head->left=temp1;
    head->right=temp2;
    temp1->left=temp3;
    temp1->right=temp4;
    // temp2->left=temp5;
    temp2->right=temp6;
    temp4->left=temp7;
    TreeNode* p=head;
    if(isParityTree1(p)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    if(isParityTree2(p,1)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}