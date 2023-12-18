#include <iostream>
#include <string>
using namespace std;

// 定义二叉排序树的结构体
struct BSTNode {
    string color; // 气球的颜色
    int count; // 气球的数量
    BSTNode* left; // 左子树
    BSTNode* right; // 右子树
    BSTNode(string c) : color(c), count(1), left(NULL), right(NULL) {} // 构造函数
};

// 定义插入函数
void insert(BSTNode*& root, string c) {
    if (root == NULL) { // 如果根节点为空，就创建一个新节点
        root = new BSTNode(c);
    } else if (c < root->color) { // 如果气球的颜色字典序小于当前节点的颜色，就插入到左子树
        insert(root->left, c);
    } else if (c > root->color) { // 如果气球的颜色字典序大于当前节点的颜色，就插入到右子树
        insert(root->right, c);
    } else { // 如果气球的颜色和当前节点的颜色相同，就将当前节点的数量加一
        root->count++;
    }
}

// 定义遍历函数
void traverse(BSTNode* root, string& ans, int& maxCount) {
    if (root == NULL) return; // 如果根节点为空，就返回
    traverse(root->left, ans, maxCount); // 遍历左子树
    if (root->count > maxCount) { // 如果当前节点的数量大于最大数量，就更新答案和最大数量
        ans = root->color;
        maxCount = root->count;
    } else if (root->count == maxCount && root->color < ans) { // 如果当前节点的数量等于最大数量，且当前节点的颜色字典序小于答案，就更新答案
        ans = root->color;
    }
    traverse(root->right, ans, maxCount); // 遍历右子树
}

// 定义主函数
int main() {
    int T; // 测试数据的组数
    cin >> T;
    while (T--) {
        int n; // 气球的总数
        cin >> n;
        BSTNode* root = NULL; // 创建一个空的二叉排序树
        while (n--) {
            string c; // 气球的颜色
            cin >> c;
            for (char& ch : c) { // 将气球的颜色转换为小写
                ch = tolower(ch);
            }
            insert(root, c); // 将气球的颜色和数量插入到二叉排序树中
        }
        string ans = ""; // 签到题对应的气球颜色
        int maxCount = 0; // 签到题被AC的次数
        traverse(root, ans, maxCount); // 从二叉排序树中找出答案
        cout << ans << endl; // 输出答案
    }
    return 0;
}
