#include<iostream>
#include<string>
#include<stack>
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
TreeNode* PreOrderDeSerialize(string& s)
{
    if (s.empty())
        return nullptr;
    if (s[0] == '*')
    {
        s = s.substr(1);
        return nullptr;
    }
    TreeNode* node = new TreeNode(s[0]-'0');
    s = s.substr(1);
    node->left = PreOrderDeSerialize(s);
    node->right = PreOrderDeSerialize(s);
    return node;
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

int main(){
    string s;
    while (cin>>s)
    {
        
        if(s.empty()){
            break;
        }
        TreeNode* head=PreOrderDeSerialize(s);
        

        if(checkBST3(head)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        preValue=INT_MIN;
    }
    
    
    
}