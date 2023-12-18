#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<cmath>
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
//利用中序遍历(递归)进行搜索二叉树的判断
int preValue=INT_MIN;
bool checkBST(TreeNode* head){
    if(head==nullptr){
        return true;
    }
    bool isLeftBst= checkBST(head->left);//判断左子树是不是搜索二叉树 
    //在中序遍历中，这个地方是打印行为，这里就变成处理比较行为
    if(!isLeftBst){
        return false;
    }
    if(head->val<=preValue){ //如果值降序，说明不是搜索二叉树
        return false;
    }
    else{
        preValue=head->val; //记录当前结点的值
    }
    return checkBST(head->right); //判断右子树是不是搜索二叉树
}
//利用中序遍历(非递归)进行搜索二叉树的判断
bool checkBST2(TreeNode* head){
    if(head==nullptr){
        return true;
    }
    stack<TreeNode*> stk;
    int  preValue=-1;
    while (!stk.empty()||head!=nullptr)
    {
        if(head!=nullptr){ //一直找左孩子，直到为空
            stk.push(head);
            head=head->left;  
        }
        else{  //为空后，弹出结点，打印，然后找右孩子
            head=stk.top();
            stk.pop();
            if(head->val<=preValue){//在中序遍历中，这个地方是打印行为，这里就变成处理比较行为
                return false;
            }
            else{
                preValue=head->val;
            }
            head=head->right;
        }

    }
    return true;
}
//利用树型dp（动态规划）判断搜索二叉树
class ReturnData{ //定义一个返回数据类，返回三个数据，对左子树需要最大值，对右子树需要最小值，取全集
    public:
        bool isBST;
        int Min;
        int Max;
        ReturnData(bool is,int mi, int ma){
            isBST= is;
            Min= mi;
            Max=ma;
        }
};
ReturnData* process1(TreeNode* x){
    if(x==nullptr){
        return nullptr; //必须这么返回，因为你不管怎么设最大最小都有干扰
    }
    ReturnData* leftData=process1(x->left); //得到左子树的数据
    ReturnData* rightData=process1(x->right); //得到右子树的数据
    //找x的最小，最大
    int Min=x->val;
    int Max=x->val;
    if(leftData!=nullptr){
        Min=min(Min,leftData->Min);
        Max=max(Max,leftData->Max);
    }
    if(rightData!=nullptr){
        Min=min(Min,rightData->Min);
        Max=max(Max,rightData->Max);
    }
    //判断是否是搜索二叉树
    bool isBST=true;
    if(leftData!=nullptr&&(!leftData->isBST||leftData->Max>=x->val)){
        isBST=false;
    }
    if(rightData!=nullptr&&(!rightData->isBST||rightData->Min<=x->val)){
        isBST=false;
    }
    return new ReturnData(isBST,Min,Max);
}
bool checkBST3(TreeNode* head){
    return process1(head)->isBST;
}


//用宽度优先遍历判断是否是完全二叉树
bool checkCBT(TreeNode* head){
     if(head==nullptr){
        return true;
    }
    queue<TreeNode*> q;
    bool leaf=false;
    q.push(head);
    while (!q.empty())
    {
        TreeNode* cur=q.front(); //一层一层弹出
        q.pop();
        //两个条件，1.对任一结点，有右无左 false，2.在1不成立条件下，如果遇到第一个左右子结点不全，后续都是叶节点
        if((cur->left==nullptr&&cur->right!=nullptr)||(leaf&&(cur->left!=nullptr||cur->right!=nullptr))){
            return false;
        }
        if(cur->left!=nullptr){ //先进左结点，先出
            q.push(cur->left);
        }
        if(cur->right!=nullptr){//先进右结点，后出
            q.push(cur->right);
        }
        if(cur->left==nullptr||cur->right==nullptr){ //判断是否是叶结点
            leaf=true;
        }
        
    }
    return true;
}
//利用树型dp判断是否是平衡二叉树
class ReturnType{ //设置两个返回数据
    public:
        bool isBalanced;
        int height;
        ReturnType(bool isB,int hei){
            isBalanced=isB;
            height=hei;

        }
};
ReturnType process2(TreeNode* x){
    if(x==nullptr){ 
        return ReturnType(true,0);
    }

    ReturnType leftData=process2(x->left); //通过递归得到左树的数据
    ReturnType rightData=process2(x->right);//得到右数的数据

    int height=max(leftData.height,rightData.height)+1; //获取高度信息
    //获取是否是平衡二叉树的信息
    bool isBalanced=leftData.isBalanced&&rightData.isBalanced&&abs(leftData.height-rightData.height)<2;
    
    return  ReturnType(isBalanced,height);//返回两信息，x是否是平衡树
    
}
bool checkBalanced(TreeNode* head){
    return process2(head).isBalanced;
}

//判断是否是满二叉树,用性质结点数=2^深度-1
class Info{  //返回数据类型，返回两数据
    public:
        int height; //深度
        int nodes; //结点数
        Info(int h,int n){
            height=h;
            nodes=n;
        }
};
Info process3(TreeNode *x){
    if(x==nullptr){
        return Info(0,0);
    }
    Info leftData=process3(x->left); 
    Info rightData=process3(x->right);
    int height=max(leftData.height,rightData.height)+1; //计算当前节点的高度
    int nodes=leftData.nodes+rightData.nodes+1; //计算当前节点的所有结点数
    return Info(height,nodes);
}
bool checkFull(TreeNode* head){
    if(head==nullptr){
        return true;
    }
    // return pow(2,process3(head).height)-1==process3(head).nodes?true:false;
    return process3(head).nodes==((1<<process3(head).height)-1)?true:false; //用位运算计算次方
}

int main(){
    TreeNode* head=new TreeNode(4);
    TreeNode* temp1=new TreeNode(2);
    TreeNode* temp2=new TreeNode(6);
    TreeNode* temp3=new TreeNode(1);
    TreeNode* temp4=new TreeNode(3);
    TreeNode* temp5=new TreeNode(5);
    TreeNode* temp6=new TreeNode(7);
    head->left=temp1;
    head->right=temp2;
    temp1->left=temp3;
    temp1->right=temp4;
    temp2->left=temp5;
    temp2->right=temp6;
    TreeNode* p=head;
    cout<<"——————判断搜索二叉树——————"<<endl;
    if(checkBST(p)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    if(checkBST2(p)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    if(checkBST3(p)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    cout<<"——————判断完全二叉树——————"<<endl;
    if(checkCBT(p)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    cout<<"——————判断平衡二叉树——————"<<endl;
    if(checkBalanced(p)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    cout<<"——————判断满二叉树——————"<<endl;
    if(checkFull(p)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}