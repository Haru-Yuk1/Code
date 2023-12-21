#include<iostream>
using namespace std;
#define  MaxVexNum   20     //最大顶点数目
typedef struct 
{    int  arcs[MaxVexNum][MaxVexNum];
     int  vexnum, arcnum;
}AMGraph;

void dfs(AMGraph graph,int v){
    
}
int main(){
    int Vexnum,Arcnum;
    AMGraph graph;
    cin>>Vexnum>>Arcnum;
    graph.vexnum=Vexnum;
    graph.arcnum=Arcnum;
    for(int i=0;i<MaxVexNum;i++){
        for(int j=0;j<MaxVexNum;j++){
            graph.arcs[i][j]=0;
        }
    }
    for(int i=0;i<Arcnum;i++){
        int from,to;
        cin>>from>>to;
        graph.arcs[from][to]=1;
    }
    for(int i=0;i<MaxVexNum;i++){
        for(int j=0;j<MaxVexNum;j++){
            cout<<graph.arcs[i][j];
        }
        cout<<endl;
    }
}
