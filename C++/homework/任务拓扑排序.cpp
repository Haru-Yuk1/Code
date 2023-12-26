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
//构造图的函数，matrix 第一列为权重，如果，第二列为来点，第三列为出点 [i][j] i是行 j是列
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
//拓扑排序的DFS算法
list<Node*> sortedTopology(Graph graph)
{
	unordered_map<Node*,int> inMap;			//存储节点与入度 
	queue<Node*> zeroInQueue;				//存储入度为零的节点 
	unordered_map<int,Node*>::iterator ite = graph.nodes.begin();
	//遍历图中的所有节点，把所有入度为零的节点放入队列 
	while(ite != graph.nodes.end())								
	{
		inMap.insert(pair<Node*,int>(ite->second,ite->second->in));
		if(ite->second->in == 0)
			zeroInQueue.push(ite->second);
		ite++;
	}
	//输出入度为零的节点
	//把入度为零的节点所指向的节点的入度减一（相当于删去当前节点）并没有实际删除该节点
	//若又有入度为零的节点加入队列
	list<Node*> result;
	while(!zeroInQueue.empty())
	{
		Node* help = zeroInQueue.front();
		zeroInQueue.pop();
		result.push_back(help);
		// cout<<help->value<<" ";
		for(Node* t : help->nexts)			 
		{
			if(--inMap.find(t)->second == 0)    //去掉这个入度为0的点后又有入度为零的节点加入队列
				zeroInQueue.push(t);
		}
	}
	return result;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> matrix(e,vector<int>(3,0));
    if(n<e-1){
        cout<<"unworkable project";
        return 0;
    }
    for(int i=0;i<e;i++){
        int to,from;
        cin>>to>>from;
        matrix[i][0]=1;
        matrix[i][1]=to;
        matrix[i][2]=from;
    }
    
    // for(int i=0;i<e;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    Graph graph = createGraph(matrix);
    for(int i=0;i<n;i++){
        if(!graph.nodes.count(i)){
            Node* tmp=new Node(i);
            graph.nodes.emplace(i,tmp);
        }
    }
	list<Node*> res =sortedTopology(graph);

    if(res.empty()){
        cout<<"unworkable project";
    }else{
        for(auto node:res){
            cout<<node->value<<" ";
        }
    }
    
}