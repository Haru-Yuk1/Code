// C++代码，用邻接矩阵表示图
#include <iostream>
using namespace std;

// 定义图的最大顶点数
const int MAX_V = 100;

// 定义图的类
class Graph {
    private:
        // 用二维数组存储邻接矩阵
        int adjMatrix[MAX_V][MAX_V];
        // 用一个变量记录图的顶点数
        int numVertices;
    public:
        // 构造函数，初始化邻接矩阵和顶点数
        Graph(int n) {
            numVertices = n;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adjMatrix[i][j] = 0; // 初始时没有边
                }
            }
        }
        int getNumVertices(){
            return numVertices;
        }
        // 添加一条从v1到v2的有向边，权重为w
        void addEdge(int v1, int v2, int w) {
            // 检查v1和v2是否有效
            if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
                adjMatrix[v1][v2] = w; // 在邻接矩阵中设置权重
            }
            else {
                cout << "无效的顶点" << endl;
            }
        }

        // 删除一条从v1到v2的有向边
        void removeEdge(int v1, int v2) {
            // 检查v1和v2是否有效
            if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
                adjMatrix[v1][v2] = 0; // 在邻接矩阵中清除权重
            }
            else {
                cout << "无效的顶点" << endl;
            }
        }

        // 判断是否存在从v1到v2的有向边
        bool isEdge(int v1, int v2) {
            // 检查v1和v2是否有效
            if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
                return adjMatrix[v1][v2] != 0; // 如果权重不为0，说明有边
            }
            else {
                cout << "无效的顶点" << endl;
                return false;
            }
        }

        // 获取从v1到v2的有向边的权重
        int getWeight(int v1, int v2) {
            // 检查v1和v2是否有效
            if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
                return adjMatrix[v1][v2]; // 返回权重
            }
            else {
                cout << "无效的顶点" << endl;
                return 0;
            }
        }

        // 打印邻接矩阵
        void printMatrix() {
            for (int i = 0; i < numVertices; i++) {
                for (int j = 0; j < numVertices; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

// 测试代码
int main() {
    // 创建一个有5个顶点的图
    Graph g(5);

    // 添加一些边
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 5);

    // 打印邻接矩阵
    g.printMatrix();

    // 测试一些边的情况
    cout << "是否有从0到1的边：" << g.isEdge(0, 1) << endl;
    cout << "是否有从1到0的边：" << g.isEdge(1, 0) << endl;
    cout << "从0到2的边的权重：" << g.getWeight(0, 2) << endl;

    // 删除一些边
    g.removeEdge(0, 1);
    g.removeEdge(3, 4);

    // 再次打印邻接矩阵
    g.printMatrix();

    return 0;
}
