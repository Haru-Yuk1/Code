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
//
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
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // 计算当前节点的平衡因子
    int balance = getBalance(root);

    // 如果平衡因子的绝对值大于1，说明树不平衡，需要进行旋转操作

    // 左左情况，对当前节点进行右旋
    if (balance > 1 && val < root->left->val) return rightRotate(root);

    // 左右情况，先对左子节点进行左旋，然后对当前节点进行右旋
    if (balance > 1 && val > root->left->val)
    {
        root->left = leftRotate(root->left);
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
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // 计算当前节点的平衡因子
    int balance = getBalance(root);

    // 如果平衡因子的绝对值大于1，说明树不平衡，需要进行旋转操作

    // 左左情况，对当前节点进行右旋
    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);

    // 左右情况，先对左子节点进行左旋，然后对当前节点进行右旋
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 右右情况，对当前节点进行左旋
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);

    // 右左情况，先对右子节点进行右旋，然后对当前节点进行左旋
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // 如果树平衡，直接返回当前节点
    return root;
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

}