#include<iostream>
using namespace std;
struct TreeNode
{
    int val; // 节点的值
    TreeNode* right; // 右子节点的指针
    TreeNode* left; // 左子节点的指针
    int height; // 节点的高度
    TreeNode():val(0),right(nullptr),left(nullptr),height(0){}
    TreeNode(int x):val(x),right(nullptr),left(nullptr),height(0){}
    TreeNode(int x,TreeNode* left,TreeNode* right ):val(x),left(left),right(right),height(0){}
};

//得到节点的高度
int getHeight(TreeNode* node)
{
    if (node == nullptr) return 0;
    return node->height;
}
//更新节点的高度
void UpdateHeight(TreeNode* node){
    if(node!=nullptr){
        int leftHeight=getHeight(node->left); //左子树高度
        int rightHeight=getHeight(node->right); //右子树高度
        node->height=max(leftHeight,rightHeight)+1; //更新该节点高度
    }
}
//获取结点的平衡因子
int getBalance(TreeNode* node)
{
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}
//右旋
TreeNode* rightRotate(TreeNode* node)
{
    // 保存节点的左子节点和左子节点的右子节点
    TreeNode* left = node->left;
    TreeNode* leftRight = left->right;

    // 将节点的左子节点作为新的根节点，将节点作为新根节点的右子节点
    left->right = node;
    node->left = leftRight;

    // 更新节点和新根节点的高度
    UpdateHeight(node);
    UpdateHeight(left);

    // 返回新的根节点
    return left;
}
//左旋
TreeNode* leftRotate(TreeNode* node)
{
    // 保存节点的右子节点和右子节点的左子节点
    TreeNode* right = node->right;
    TreeNode* rightLeft = right->left;

    // 将节点的右子节点作为新的根节点，将节点作为新根节点的左子节点
    right->left = node;
    node->right = rightLeft;

    // 更新节点和新根节点的高度
    UpdateHeight(node);
    UpdateHeight(right);

    // 返回新的根节点
    return right;
}
TreeNode* SearchBSTRecur(TreeNode* root,int val){
    if(root==nullptr||root->val==val){
        return root;
    }
    if(val<root->val){ //key的值小于根，往左子树查找
        return SearchBSTRecur(root->left,val);
    }
    else{ //key的值大于根，往右子树查找
        return SearchBSTRecur(root->right,val);
    }
}
TreeNode* SearchBSTUnRecur(TreeNode* root,int val){
    TreeNode* node=root;
    while (node!=nullptr && node->val!=val)
    {
        if(val<node->val){//key的值小于根，往左子树查找
            node=node->left;
        }
        else{//key的值大于根，往右子树查找
            node=node->right;
        }
    }
    return node;
    
}
//对AVL树插入与删除后的维护平衡
TreeNode* Balancing(TreeNode* root,int val){
    // 计算当前节点的平衡因子
    int balance = getBalance(root);

    // 如果平衡因子的绝对值大于1，说明树不平衡，需要进行旋转操作

    // 左左情况，对当前节点进行右旋
    if (balance > 1 && val < root->left->val) return rightRotate(root);

    // 左右情况，先对左子节点进行左旋，然后对当前节点进行右旋
    if (balance > 1 && val > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
        // 右右情况，对当前节点进行左旋
    if (balance < -1 && val > root->right->val) return leftRotate(root);

    // 右左情况，先对右子节点进行右旋，然后对当前节点进行左旋
    if (balance < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // 如果树平衡，直接返回当前节点
    return root;
}
//插入操作可以直接调用BST中的插入算法
TreeNode* insert(TreeNode* root, int val)
{
    // 如果树为空，直接创建一个新的节点作为根节点
    if (root == nullptr) return new TreeNode(val);

    // 如果值小于当前节点的值，递归地向左子树插入
    if (val < root->val) root->left = insert(root->left, val);

    // 如果值大于当前节点的值，递归地向右子树插入
    else if (val > root->val) root->right = insert(root->right, val);

    // 如果值等于当前节点的值，不进行插入，直接返回当前节点
    else return root;

    // 插入后，更新当前节点的高度
    UpdateHeight(root);
    
    //返回经过平衡后的节点
    return Balancing(root,val);
   
}

TreeNode* deleteNode(TreeNode* root, int val)
{
    // 如果树为空，直接返回空
    if (root == nullptr) return nullptr;

    // 如果要删除的值小于当前节点的值，递归地向左子树删除
    if (val < root->val) root->left = deleteNode(root->left, val);

    // 如果要删除的值大于当前节点的值，递归地向右子树删除
    else if (val > root->val) root->right = deleteNode(root->right, val);

    // 如果要删除的值等于当前节点的值，分为以下几种情况

    else
    {
        // 如果节点没有子节点，直接删除节点，并返回空
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // 如果节点只有一个子节点，直接用子节点替换节点，并返回子节点
        else if (root->left == nullptr || root->right == nullptr)
        {
            TreeNode* child = root->left ? root->left : root->right;
            delete root;
            return child;
        }

        // 如果节点有两个子节点，找到节点的后继节点（右子树的最小节点），用后继节点的值替换节点的值，然后递归地在右子树删除后继节点
        else
        {
            TreeNode* successor = root->right;
            while (successor->left) successor = successor->left;
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
    }

    // 删除后，更新当前节点的高度
    UpdateHeight(root);

    //返回平衡后的节点
    return Balancing(root,val);
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
    head->height=2;
    temp1->height=1;
    temp2->height=1;
    
    InOrderRecur(head);
    cout<<endl;
    
    cout<<"————删除节点————"<<endl;
    deleteNode(head,2);
    InOrderRecur(head);
    cout<<endl;
    cout<<"————插入节点————"<<endl;
    insert(head,8);
    InOrderRecur(head);
    cout<<endl;
    cout<<"————查找节点————"<<endl;
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
    cout<<endl;
}