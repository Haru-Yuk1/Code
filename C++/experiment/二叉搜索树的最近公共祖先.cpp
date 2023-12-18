#include <iostream>
#include <vector>
using namespace std;

// 定义二叉搜索树的结点结构
struct TreeNode {
    int val; // 结点的键值
    TreeNode* left; // 左子结点
    TreeNode* right; // 右子结点
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // 构造函数
};

// 根据先序遍历序列，递归地构建一棵二叉搜索树
TreeNode* buildTree(vector<int>& preorder, int low, int high) {
    if (low > high) return NULL; // 递归终止条件
    TreeNode* root = new TreeNode(preorder[low]); // 创建根结点
    int mid = low + 1; // 找到左右子树的分界点
    while (mid <= high && preorder[mid] < root->val) mid++;
    root->left = buildTree(preorder, low + 1, mid - 1); // 构建左子树
    root->right = buildTree(preorder, mid, high); // 构建右子树
    return root; // 返回根结点
}

// 在二叉搜索树中，查找两个结点的最近公共祖先
TreeNode* findLCA(TreeNode* root, int u, int v) {
    if (root == NULL) return NULL; // 递归终止条件
    if (root->val == u || root->val == v) return root; // 如果根结点是其中一个结点，直接返回
    TreeNode* left = findLCA(root->left, u, v); // 在左子树中查找
    TreeNode* right = findLCA(root->right, u, v); // 在右子树中查找
    if (left != NULL && right != NULL) return root; // 如果左右子树都不为空，说明根结点是最近公共祖先
    if (left == NULL) return right; // 如果左子树为空，返回右子树的结果
    else return left; // 如果右子树为空，返回左子树的结果
}

// 判断一个结点是否在二叉搜索树中
bool isFound(TreeNode* root, int x) {
    if (root == NULL) return false; // 递归终止条件
    if (root->val == x) return true; // 如果找到了，返回真
    if (root->val > x) return isFound(root->left, x); // 如果键值大于x，往左子树查找
    else return isFound(root->right, x); // 如果键值小于x，往右子树查找
}

int main() {
    int M, N; // 待查询的结点对数和二叉搜索树中结点个数
    cin >> M >> N;
    vector<int> preorder(N); // 先序遍历序列
    for (int i = 0; i < N; i++) {
        cin >> preorder[i];
    }
    TreeNode* root = buildTree(preorder, 0, N - 1); // 构建二叉搜索树
    for (int i = 0; i < M; i++) {
        int u, v; // 待查询的两个结点
        cin >> u >> v;
        bool hasu = isFound(root, u); // 判断u是否在树中
        bool hasv = isFound(root, v); // 判断v是否在树中
        if (!hasu && !hasv) { // 如果都不在，输出错误信息
            cout << "ERROR: " << u << " and " << v << " are not found." << endl;
        }
        else if (!hasu) { // 如果u不在，输出错误信息
            cout << "ERROR: " << u << " is not found." << endl;
        }
        else if (!hasv) { // 如果v不在，输出错误信息
            cout << "ERROR: " << v << " is not found." << endl;
        }
        else { // 如果都在，查找最近公共祖先
            TreeNode* lca = findLCA(root, u, v);
            if (lca->val == u) { // 如果u是v的祖先，输出信息
                cout << u << " is an ancestor of " << v << "." << endl;
            }
            else if (lca->val == v) { // 如果v是u的祖先，输出信息
                cout << v << " is an ancestor of " << u << "." << endl;
            }
            else { // 如果u和v有其他的公共祖先，输出信息
                cout << "LCA of " << u << " and " << v << " is " << lca->val << "." << endl;
            }
        }
    }
    return 0;
}
