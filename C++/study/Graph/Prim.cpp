#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
class Edge;
//节点的五个数据，值，入度，出度，下一节点，该节点出发的边
class Node{
    public:
        int value;  //节点的值
        int in;	  	//入度
        int out;	//出度
        list<Node*> nexts; //下一节点
        list<Edge*> edges; //该节点出发的边
        Node(int value){   //构造函数 初始化
            this->value=value;
            in=0;
            out=0;
        }
};
// Graph类有点和边两大部分，使用hash_map存储节点,使用hash_set存储边的信息
class Graph{
    public: 
        unordered_map<int,Node*> nodes;  	//点集
        unordered_set<Edge*> edges;  		//边集
        Graph(){};
        Graph(Node* node,Edge* edge){
            nodes.emplace(1,node);
            edges.emplace(edge);
            
        }

};

// 边上的权重、当前边的from和to节点
class Edge{
    public:
        int weight;	//权重
        Node* from;	//来点
        Node* to;	//去点
        Edge(int weight,Node* from,Node* to){
            this->weight=weight;
            this->from=from;
            this->to=to;
        }
};
//构造图的函数，matrix 第一列为权重，如果，第二列为来点，第三列为出点
Graph createGraph(vector<vector<int>> matrix){
    Graph graph;
    for(int i=0;i<matrix.size();i++){
        int weight=matrix[i][0];
        int from = matrix[i][1];
		int to = matrix[i][2];
		//Graph的node里不含有from节点、to节点时建上 
		if(graph.nodes.find(from) == graph.nodes.end())
			graph.nodes[from] = new Node(from);
		if(graph.nodes.find(to) == graph.nodes.end())
			graph.nodes[to] = new Node(to);
		//拿出from，to点
		Node* fromNode = graph.nodes[from];		
		Node* toNode = graph.nodes[to];
		//Node* fromNode = graph.nodes.find(from)->second;		
		//Node* toNode = graph.nodes.find(to)->second;
		//新建边 
		Edge* newEdge = new Edge(weight, fromNode, toNode);
		
		//增加节点的四个数据
		fromNode->nexts.push_back(toNode);
		fromNode->edges.push_back(newEdge);
		fromNode->out++;
		toNode->in++;
		graph.edges.insert(newEdge);
    }
    return graph;
}
//重载堆的比较器
struct  cmp
{
    bool operator()(Edge* a,Edge* b){
        return a->weight>b->weight;
    }
};
unordered_set<Edge*> primMST(Graph graph){
    //用小顶堆来存储边，并通过边的权重比较，这样能先输出权重小的
    priority_queue<Edge*,vector<Edge*>,cmp> priorityQueue;
    unordered_set<Node*> set;                   //定义一个集合用来判断是否加入过该节点
    unordered_set<Edge*> result;            
    for(auto node:graph.nodes){                 //遍历图的节点，其实如果是连通图不需要这个外层循环，害怕有森林的那种情况
        if(!set.count(node.second)){            //如果该点不在集合内
            set.emplace(node.second);           
            for(auto edge:node.second->edges){  //遍历该节点的所有边，把边放入小顶堆
                priorityQueue.emplace(edge);
            }
            while(!priorityQueue.empty()){      //如果堆不为空，弹出边，并判断该边的下一节点是否在集合里
                Edge* edge=priorityQueue.top(); 
                priorityQueue.pop();
                Node* toNode=edge->to;
                if(!set.count(toNode)){         //如果边的下一节点不在集合里，则放入集合，再把该点的所有边放入堆
                    set.emplace(toNode);
                    result.emplace(edge);
                    for(Edge* nextEdge:toNode->edges){
                        priorityQueue.emplace(nextEdge);
                    }
                }
            }
        }
    }
    return result;
}
int main(){
    vector<vector<int> > matrix= {{7,1,2},{7,2,1},{2,1,3},{2,3,1},{10,1,4},{10,4,1},{100,2,5},{100,5,2}
    ,{11,2,4},{11,4,2},{4,3,4},{4,4,3}};
	Graph graph = createGraph(matrix);
    unordered_set<Edge*> result=primMST(graph);
    for(auto edge: result){
        cout<<"该边的来点的值:"<<edge->from->value<<"该边的去点的值:"<<edge->to->value<<"该边权重:"<<edge->weight<<endl;
    }
}