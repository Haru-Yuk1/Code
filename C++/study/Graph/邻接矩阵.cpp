#include<iostream>
using namespace std;
#define MaxVertexNum 100
//用邻接矩阵存储,可表示无权和加权
struct MGraph
{
    int Vex[MaxVertexNum];  //顶点数组
    int Edge[MaxVertexNum][MaxVertexNum];   //邻接矩阵用二维数组表示边
    int VexNum,ArcNum; //当前顶点数和边数
    bool directed;
    MGraph():Vex({0}),Edge({0}),VexNum(0),ArcNum(0),directed(false){}
};

int NumberofVex(MGraph* graph){
    return graph->VexNum;
}
// 判断u到v是否存在边
bool ExistEdge(MGraph* graph,int u,int v){
    if(u<graph->VexNum&&v<graph->VexNum){
        if(u!=v&&graph->Edge[u][v]!=0){
            return true;

        }
    }
    return false;
}
//在u到v插入边
void InsertEdge(MGraph* graph,int u,int v,int weight){
    if(u!=v&&ExistEdge(graph,u,v)==false){
        graph->Edge[u][v]=weight;
        graph->ArcNum++;
        if(graph->directed==false){
            graph->Edge[v][u]=weight;
        }
    }

}

void RemoveVex(MGraph* graph,int v){
    
}
int main(){
    
    
}