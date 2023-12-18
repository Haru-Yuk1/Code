#include <iostream>
using namespace std;

#define MaxVexNum 20 //最大顶点数目
typedef struct
{
    int arcs[MaxVexNum][MaxVexNum]; //邻接矩阵
    int vexnum, arcnum;             //顶点数和边数
} AMGraph;

bool visited[MaxVexNum]; //访问标记数组
int cc = 0;              //连通分量个数
int ec = 0;              //边的数目

//从顶点v开始深度优先遍历图G
void DFS(AMGraph G, int v)
{
    cout << v << " "; //输出顶点编号
    visited[v] = true; //标记顶点v已访问
    for (int w = 0; w < G.vexnum; w++)
    {
        if (G.arcs[v][w] == 1) //如果v和w邻接
        {
            ec++; //边的数目加一
            if (!visited[w])
                DFS(G, w); //如果w未访问，递归访问w
        }
    }
}

//深度优先遍历图G
void DFSTraverse(AMGraph G)
{
    for (int v = 0; v < G.vexnum; v++)
        visited[v] = false; //初始化访问标记数组
    for (int v = 0; v < G.vexnum; v++)
    {
        if (!visited[v]) //如果v未访问
        {
            cc++;        //连通分量个数加一
            DFS(G, v);   //从v开始深度优先遍历
        }
    }
}

//创建无向图的邻接矩阵
void CreateUDG(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum; //输入顶点数和边数
    for (int i = 0; i < G.vexnum; i++)
        for (int j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = 0; //初始化邻接矩阵
    for (int k = 0; k < G.arcnum; k++)
    {
        int i, j;          //输入边依附的两个顶点的编号
        cin >> i >> j;     //假设顶点编号从0开始
        G.arcs[i][j] = 1;  //无向图的邻接矩阵是对称的
        G.arcs[j][i] = 1;  //边的权值为1
    }
}

int main()
{
    AMGraph G;      //定义图G
    CreateUDG(G);   //创建无向图的邻接矩阵
    DFSTraverse(G); //深度优先遍历图G
    cout << endl
         << cc << endl; //输出连通分量个数
    cout << ec / 2 << endl; //输出边的数目，注意要除以2，因为每条边被计算了两次
    return 0;
}
