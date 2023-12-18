#include <iostream>
#include <vector>
#include<stack>
using namespace std;

// 定义二叉树结点的结构体
struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode():val(0),right(nullptr),left(nullptr){}
    TreeNode(int x):val(x),right(nullptr),left(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right ):val(x),left(left),right(right){}
};
// 根据后序遍历序列和中序遍历序列建立二叉树
TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
    // 如果序列为空，返回空指针
    if (postorder.empty() || inorder.empty()) {
        return NULL;
    }
    // 后序遍历序列的最后一个元素是根节点的值
    int rootValue = postorder.back();
    // 创建根节点
    TreeNode* root = new TreeNode(rootValue);
    // 在中序遍历序列中找到根节点的位置
    int rootIndex = -1;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == rootValue) {
            rootIndex = i;
            break;
        }
    }
    // 如果没有找到，说明序列不合法，返回空指针
    if (rootIndex == -1) {
        return NULL;
    }
    // 计算左子树和右子树的结点个数
    int leftSize = rootIndex;
    int rightSize = inorder.size() - rootIndex - 1;
    // 创建左子树和右子树的后序遍历序列和中序遍历序列
    vector<int> leftPost(postorder.begin(), postorder.begin() + leftSize);
    vector<int> rightPost(postorder.begin() + leftSize, postorder.end() - 1);
    vector<int> leftIn(inorder.begin(), inorder.begin() + leftSize);
    vector<int> rightIn(inorder.begin() + rootIndex + 1, inorder.end());
    // 递归地建立左子树和右子树
    root->left = buildTree(leftPost, leftIn);
    root->right = buildTree(rightPost, rightIn);
    // 返回根节点
    return root;
}

// 计算二叉树的深度
int depth(TreeNode* root) {
    // 如果根节点为空，深度为0
    if (root == NULL) {
        return 0;
    }
    // 递归地计算左子树和右子树的深度
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    // 返回较大的深度加一
    return max(leftDepth, rightDepth) + 1;
}

void PreOrderUnRecur(TreeNode* head,int last){
    if(head==nullptr){
        return;
    }
    stack<TreeNode*> stk;
    stk.push(head);
    while (!stk.empty())
    {
        head=stk.top();
        stk.pop();
        if(head->val==last){
            cout<<head->val;
        }
        else{
            cout<<head->val<<" ";
        }
        

        if(head->right!=nullptr){ //先压右孩子，后出，即后打印右
            stk.push(head->right);
        }
        if(head->left!=nullptr){ //后压左孩子，先出，即先打印左
            stk.push(head->left);
        }
        

    }
}

int main() {
    // 输入结点数
    int n;
    cin >> n;
    // 输入后序遍历序列
    vector<int> postorder(n);
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    // int m;
    // cin>>m;
    // 输入中序遍历序列
    vector<int> inorder(n);
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    // 建立二叉树
    TreeNode* root = buildTree(postorder, inorder);
    // 计算二叉树的深度
    int d = depth(root);
    // 输出二叉树的深度
    cout << d << " ";
    // 先序遍历二叉树
    PreOrderUnRecur(root,inorder[n-1]);
    // 输出换行符
    cout << endl;
    return 0;
}
