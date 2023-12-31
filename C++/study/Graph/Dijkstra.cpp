#include<iostream>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
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

// 没有用堆的D算法
Node* getMinDistanceAndUnselectedNode(unordered_map<Node*,int> distanceMap,unordered_set<Node*> selectedNodes){
    Node* minNode=nullptr;
    int mindistance=INT32_MAX;
    for(auto entry:distanceMap){
        Node* node=entry.first;
        int distance=entry.second;
        if(!selectedNodes.count(node)&&distance<mindistance){ //如果没被选过，并且距离更小
            minNode=node;
            mindistance=distance;
        }
    }
    return minNode;
}
unordered_map<Node*,int> Dijkstra1(Node* head){
    //从head出发到所有点的最小距离
    //key：从head出发到达key
    //value：从head出发到达key的最小距离
    //如果在表中，没有T的记录，含义是从head出发到T这个点的距离为正无穷
    unordered_map<Node*,int> distanceMap;
    distanceMap.emplace(head,0);
    //已经求过距离的节点，存在selectedNodes中，以后再也不碰
    unordered_set<Node*> selectedNodes;
    Node* minNode=getMinDistanceAndUnselectedNode(distanceMap,selectedNodes);
    while(minNode!=nullptr){ //当所有节点进selectedNodes集合中就停止
        int distance=distanceMap[minNode];
        for(auto edge:minNode->edges){
            Node* toNode=edge->to;
            if(!distanceMap.count(toNode)){     //如果没在表内表示距离无穷，而现在能到该节点所以把表更新
                distanceMap.emplace(toNode,distance+edge->weight);
            }
            //这是将之前有过的点，进行距离更新
            distanceMap[toNode]=min(distanceMap[toNode],distance+edge->weight);
        }
        selectedNodes.emplace(minNode);     //锁住选过的点
        minNode=getMinDistanceAndUnselectedNode(distanceMap,selectedNodes); //选下一个距离最小的没选过的点
    }
    return distanceMap;
}

// //用自己写的堆优化的D算法，不能用系统的堆
// class NodeRecord{
//     public:
//         Node* node;
//         int distance;
//         NodeRecord(Node* node,int distance){
//             this->node=node;
//             this->distance=distance;
//         }
// };
// class NodeHeap{
//     private:
//         vector<Node*> *nodes; //堆的底层结构是数组
//         unordered_map<Node*,int> HeapIndexMap;  //节点与它的index，给出节点在堆上的位置
//         unordered_map<Node*,int> DistanceMap;   //节点的值（距离）
//         int size;   //目前堆上有多少节点
//     public:
//         NodeHeap(int size){
//             nodes=new vector<Node*>(size);
//             this->size=0;
//         }
//         bool isEmpty(){
//             return size==0;
//         }
//         bool isEntered(Node* node){     //node进没进来过
//             return HeapIndexMap.count(node);
//         }
//         bool inHeap(Node* node){
//             return isEntered(node)&&(HeapIndexMap[node]!=-1);
//         }
//         void swap(int index1,int index2){
//             HeapIndexMap.emplace(nodes[index1],index2);
//             HeapIndexMap.emplace(nodes[index2],index1);
            
//         }
//         void insertHeapify(Node* node,int index){
//             while(DistanceMap[&nodes[index]]<)
//         }
//         void addOrUpdateOrIgnore(Node* node,int distance){
//             if(inHeap(node)){
//                 DistanceMap.emplace(node,min(DistanceMap[node],distance));
//                 insert
//             }
//         }
// };
// //从head出发，所有head能到达的节点，生成到达每个节点的最小路径记录并返回
// unordered_map<Node*,int> Dijkstra2(Node* head,int size){
//     NodeHeap* nodeHeap=new NodeHeap(size);
//     nodeHeap;
//     unordered_map<Node*,int> result;

// }

int main(){
    vector<vector<int> > matrix= {{-3,1,2},{15,1,3},{9,1,4},{2,2,3},{2,3,2},{200,2,5},
    {200,5,2},{7,3,4},{7,4,3},{14,3,5},{14,5,3},{16,4,5},{16,5,4}};
	Graph graph = createGraph(matrix);
    unordered_map<Node*,int> result= Dijkstra1(graph.nodes[1]);

    for(auto res:result){
        
        cout<<"节点1到节点"<<res.first->value<<"的距离"<<res.second<<endl;
    }
}