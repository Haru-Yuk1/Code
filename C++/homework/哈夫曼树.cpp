#include <iostream>
#include <queue>
using namespace std;

// 定义哈夫曼树结点的结构体
struct HuffmanNode {
    int weight; // 结点的权值
    HuffmanNode* left; // 左子树指针
    HuffmanNode* right; // 右子树指针
    // 构造函数
    HuffmanNode(int w) {
        weight = w;
        left = NULL;
        right = NULL;
    }
};

// 定义优先队列的比较函数，按照权值从小到大排序
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->weight > b->weight;
    }
};

// 构造哈夫曼树，返回根结点
HuffmanNode* buildHuffmanTree(int n) {
    // 创建一个优先队列，存储所有的叶结点
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    // 输入每个叶结点的权值，并创建结点，加入到优先队列中
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        HuffmanNode* node = new HuffmanNode(w);
        pq.push(node);
    }
    // 循环n-1次，每次从优先队列中取出两个最小的结点，创建一个新的内部结点，其权值为这两个结点的权值之和，然后将这两个结点作为新结点的左右子树，再将新结点加入到优先队列中
    for (int i = 0; i < n - 1; i++) {
        HuffmanNode* a = pq.top();
        pq.pop();
        HuffmanNode* b = pq.top();
        pq.pop();
        HuffmanNode* c = new HuffmanNode(a->weight + b->weight);
        c->left = a;
        c->right = b;
        pq.push(c);
    }
    // 最后优先队列中只剩下一个结点，这就是哈夫曼树的根结点
    return pq.top();
}

// 计算哈夫曼树的带权路径长度，使用一个递归的函数，从根结点开始，累加每个结点的权值乘以其深度，直到遍历完所有的叶结点
int WPL(HuffmanNode* root, int depth) {
    // 如果根结点为空，返回0
    if (root == NULL) {
        return 0;
    }
    // 如果根结点是叶结点，返回其权值乘以其深度
    if (root->left == NULL && root->right == NULL) {
        return root->weight * depth;
    }
    // 如果根结点不是叶结点，递归地计算其左右子树的带权路径长度，并返回其和
    return WPL(root->left, depth + 1) + WPL(root->right, depth + 1);
}

int main() {
    // 输入叶结点的个数
    int n;
    cin >> n;
    // 构造哈夫曼树
    HuffmanNode* root = buildHuffmanTree(n);
    // 计算哈夫曼树的带权路径长度
    int wpl = WPL(root, 0);
    // 输出带权路径长度
    cout << wpl << endl;
    return 0;
}
