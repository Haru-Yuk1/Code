#include <iostream>
#include <queue>
using namespace std;

#define MaxPos 100000 //最大位置
bool visited[MaxPos + 1]; //访问标记数组
int dist[MaxPos + 1]; //距离数组，记录从农夫位置到每个位置所需的时间

//从农夫位置N开始广度优先搜索，找到牛位置K所需的最小时间
int BFS(int N, int K)
{
    queue<int> Q; //定义一个队列，用于存储待访问的位置
    Q.push(N); //将农夫位置N入队
    visited[N] = true; //标记位置N已访问
    dist[N] = 0; //位置N到自身的距离为0
    while (!Q.empty()) //当队列不为空时
    {
        int X = Q.front(); //取出队首元素，即当前位置
        Q.pop(); //将队首元素出队
        if (X == K) //如果当前位置等于牛位置，说明找到了牛
            return dist[X]; //返回当前位置的距离，即所需的最小时间
        //否则，考虑当前位置的三种移动方式，分别是X-1, X+1, 2*X
        for (int Y : {X - 1, X + 1, 2 * X})
        {
            //如果移动后的位置Y在合法范围内，并且未被访问过
            if (Y >= 0 && Y <= MaxPos && !visited[Y])
            {
                Q.push(Y); //将位置Y入队
                visited[Y] = true; //标记位置Y已访问
                dist[Y] = dist[X] + 1; //位置Y的距离等于位置X的距离加一
            }
        }
    }
    return -1; //如果没有找到牛，返回-1
}

int main()
{
    int N, K; //定义农夫位置N和牛位置K
    cin >> N >> K; //输入农夫位置N和牛位置K
    cout << BFS(N, K) << endl; //输出农夫抓到牛所要花费的最小分钟数
    return 0;
}
