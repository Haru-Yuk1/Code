#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<algorithm>
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
//使用递归的先序、中序、后序
void PreOrderRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    cout<<head->val<<" ";
    PreOrderRecur(head->left);
    PreOrderRecur(head->right);
}
void InOrderRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    InOrderRecur(head->left);
    cout<<head->val<<" ";
    InOrderRecur(head->right);
}
void PosOrderRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    PosOrderRecur(head->left);
    PosOrderRecur(head->right);
    cout<<head->val<<" ";
}
//使用非递归,自己压栈
void PreOrderUnRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    stack<TreeNode*> stk;
    stk.push(head);
    while (!stk.empty())
    {
        head=stk.top();
        stk.pop();
        cout<<head->val<<" ";

        if(head->right!=nullptr){ //先压右孩子，后出，即后打印右
            stk.push(head->right);
        }
        if(head->left!=nullptr){ //后压左孩子，先出，即先打印左
            stk.push(head->left);
        }
        

    }
}
void InOrderUnRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    stack<TreeNode*> stk;
    
    while (!stk.empty()||head!=nullptr)
    {
        if(head!=nullptr){ //一直找左孩子，直到为空
            stk.push(head);
            head=head->left;  
        }
        else{  //为空后，弹出结点，打印，然后找右孩子
            head=stk.top();
            stk.pop();
            cout<<head->val<<" ";
            head=head->right;
        }

    }
    
}
void PosOrderUnRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    // 两个栈，一个栈用来先序遍历(这个先序遍历是根右左不是根左右)，一个栈用来倒序
    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;
    stk1.push(head);
    while (!stk1.empty())
    {
        head=stk1.top();
        stk1.pop();
        stk2.push(head);
        if(head->left!=nullptr){  //先根右左先序遍历，然后通过栈倒序
            stk1.push(head->left);
        }
        if(head->right!=nullptr){
            stk1.push(head->right);
        }
    }
    while (!stk2.empty()){
            cout<<stk2.top()->val<<" ";
            stk2.pop();
    }
}
// 宽度优先遍历，使用队列
void widthTraversal(TreeNode* head){
    if(head==nullptr){
        return;
    }
    queue<TreeNode*> q;
    q.push(head);
    while (!q.empty())
    {
        TreeNode* cur=q.front(); //一层一层弹出
        q.pop();
        cout<<cur->val<<" ";
        if(cur->left!=nullptr){ //先进左结点，先出
            q.push(cur->left);
        }
        if(cur->right!=nullptr){//后进右结点，后出
            q.push(cur->right);
        }
    }
    
}
//利用宽度优先遍历，求二叉树的宽度
int treeWidth(TreeNode* head){
    if(head==nullptr){
        return 0;
    }
    queue<TreeNode*> q;
    q.push(head);
    unordered_map<TreeNode*,int> levelMap;
    // levelMap.insert(pair<TreeNode*,int>(head,1));
    levelMap.emplace(head,1);
    int curLevel=1;
    int curLevelNodes=0;
    int Max=-1;
    while (!q.empty())
    {
        TreeNode* cur=q.front(); //一层一层弹出
        q.pop();
        int curNodeLevel=levelMap[cur]; //获取当前节点的层数
        if(curNodeLevel==curLevel){   //如果当前节点的层数是该层，则结点数加1
            curLevelNodes++;
        }else{   //否则，更新结点数的最大值，并层数+1，当前节点个数为1.
            Max=max(Max,curLevelNodes);
            curLevel++;
            curLevelNodes=1;
        }
        if(cur->left!=nullptr){ //先进左结点，先出
            levelMap.emplace(cur->left,curNodeLevel+1); //记录孩子的层数
            q.push(cur->left);
        }
        if(cur->right!=nullptr){//先进右结点，后出
            levelMap.emplace(cur->right,curNodeLevel+1); //记录孩子的层数
            q.push(cur->right);
        }
        Max=max(Max,curLevelNodes);//最后一层再比较一次
    }
    return Max;
}
int main(){
    TreeNode* head=new TreeNode(1);
    TreeNode* temp1=new TreeNode(2);
    TreeNode* temp2=new TreeNode(3);
    TreeNode* temp3=new TreeNode(4);
    TreeNode* temp4=new TreeNode(5);
    TreeNode* temp5=new TreeNode(6);
    TreeNode* temp6=new TreeNode(7);
    head->left=temp1;
    head->right=temp2;
    temp1->left=temp3;
    temp1->right=temp4;
    temp2->left=temp5;
    temp2->right=temp6;
    cout<<"——————先序遍历——————"<<endl;
    TreeNode* p=head;
    PreOrderRecur(p);
    cout<<endl;
    cout<<"——————中序遍历——————"<<endl;
    p=head;
    InOrderRecur(p);
    cout<<endl;
    cout<<"——————后序遍历——————"<<endl;
    p=head;
    PosOrderRecur(p);
    cout<<endl;
    cout<<"——————先序遍历(非递归)——————"<<endl;
    p=head;
    PreOrderUnRecur(p);
    cout<<endl;
    cout<<"——————中序遍历(非递归)——————"<<endl;
    p=head;
    InOrderUnRecur(p);
    cout<<endl;
    cout<<"——————后序遍历(非递归)——————"<<endl;
    p=head;
    PosOrderUnRecur(p);
    cout<<endl;
    cout<<"——————层次遍历——————"<<endl;
    p=head;
    widthTraversal(p);
    cout<<endl;
    cout<<"这棵树的宽度为：";
    p=head;
    int width=treeWidth(p);
    cout<<width<<endl;
    
}
