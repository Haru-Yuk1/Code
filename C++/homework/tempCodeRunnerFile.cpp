#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义一个结构体，表示一条边
struct Edge {
    int u, v, w; // u和v是边的两个端点，w是边的权值
};

// 定义一个函数，比较两条边的权值，用于排序
bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

// 定义一个数组，存储每个节点的父节点
vector<int> parent;

// 定义一个函数，查找一个节点的父节点，如果父节点是自己，就返回自己，否则递归查找
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// 定义一个函数，合并两个节点所在的集合，将一个集合的父节点指向另一个集合的父节点
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) parent[fx] = fy;
}

// 定义一个函数，实现kruskal算法，返回最小生成树的权值之和，如果不存在最小生成树，返回-1
int kruskal(int n, vector<Edge>& edges) {
    int cnt = 0, sum = 0; // cnt表示已选的边数，sum表示权值之和
    sort(edges.begin(), edges.end(), cmp); // 按照权值从小到大排序边
    for (int i = 0; i < n; i++) parent[i] = i; // 初始化每个节点的父节点为自己
    for (int i = 0; i < edges.size() && cnt < n - 1; i++) { // 遍历每条边，直到选够n-1条边或者没有边可选
        int u = edges[i].u, v = edges[i].v, w = edges[i].w; // 取出当前边的信息
        if (find(u) != find(v)) { // 如果当前边的两个端点不在同一个集合中，说明不会构成回路
            merge(u, v); // 合并两个集合
            cnt++; // 已选的边数加一
            sum += w; // 权值之和加上当前边的权值
            cout << u << "," << v << "," << w << endl; // 输出当前边的信息
        }
    }
    if (cnt == n - 1) return sum; // 如果选够了n-1条边，返回权值之和
    else return -1; // 否则返回-1，表示不存在最小生成树
}

int main() {
    int n, m; // n表示节点数，m表示边数
    cin >> n >> m; // 输入节点数和边数
    vector<Edge> edges(m); // 定义一个向量，存储所有的边
    for (int i = 0; i < m; i++) { // 输入每条边的信息
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    int ans = kruskal(n, edges); // 调用kruskal算法，得到最小生成树的权值之和
    if (ans == -1) cout << "该图不连通" << endl; // 如果返回-1，说明该图不连通
    else cout << "最小生成树的权值之和为：" << ans << endl; // 否则输出最小生成树的权值之和
    return 0;
}
