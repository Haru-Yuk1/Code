#include<iostream>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
class Edge;
//节点的五个数据，值，入度，出度，下一节点，该节点出发的边
class Node{
    public:
        int value;
        int in;
        int out;
        list<Node*> nexts;
        list<Edge*> edges;
        Node(int value){
            this->value=value;
            in=0;
            out=0;
        }
};
// Graph类有点和边两大部分，使用hash_map存储节点,使用hash_set存储边的信息
class Graph{
    public: 
        unordered_map<int,Node*> nodes;
        unordered_set<Edge*> edges;
        Graph(){};
        Graph(Node* node,Edge* edge){
            nodes.emplace(1,node);
            edges.emplace(edge);
            
        }

};

// 边上的权重、当前边的from和to节点
class Edge{
    public:
        int weight;
        Node* from;
        Node* to;
        Edge(int weight,Node* from,Node* to){
            this->weight=weight;
            this->from=from;
            this->to=to;
        }
};
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


int main(int argc, char** argv) {
	vector<vector<int> > matrix= {{7,1,2},{5,1,3},{2,2,3}};
	Graph graph = createGraph(matrix);

	//test 
	unordered_map<int,Node*>::iterator ite1 = graph.nodes.begin();
	while(ite1 != graph.nodes.end())
	{
	 	cout << "节点: "<<(ite1)->second->value<<"、";
		//cout << "节点: "<<(ite1)->first<<"、";
	 	ite1++;
	}
	cout<<endl<<"-----------------------------------------------"<<endl ;
	unordered_set<Edge*>::iterator ite = graph.edges.begin();
	while(ite != graph.edges.end())
	{
	 	cout << "边权为 "<<(*ite)->weight<<"    ";
	 	cout<<(*ite)->from->value <<"---->"<<(*ite)->to->value<<endl; 
	 	ite++;
	}
	cout<<endl<<"-----------------------------------------------"<<endl ;
	
	return 0;
}
