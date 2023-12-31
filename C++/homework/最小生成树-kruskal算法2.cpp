#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int N = 100010, M = 200010, INF = 0x3f3f3f3f;
 
int n, m;
int p[N];
 
struct Edge
{
    int a, b, w;
 
    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];
 
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
//微改一下kruskal求最小生成树的树边权重之和，res是最小权重和，如果cnt < n - 1则没有最小生成树，这题不求这个
void kruskal()
{
    sort(edges, edges + m);
 
    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集
 
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
 
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            cout<<edges[i].a<<','<<edges[i].b<<','<<w<<endl;
            res += w;
            cnt ++ ;
        }
    }
 
 
}
 
int main()
{
    scanf("%d%d", &n, &m);
 
    for (int i = 0; i < m; i ++ )
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
 
    kruskal();
 
    return 0;
}