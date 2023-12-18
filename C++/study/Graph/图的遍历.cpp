#include<iostream>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
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
//宽度优先遍历
void bfs(Node* nodes){
    if(nodes==NULL){
        return;
    }
    queue<Node*> q; //用队列来遍历
    unordered_set<Node*> set;//用集合辅助队列，防止重复
    q.push(nodes);
    set.emplace(nodes);
    while (!q.empty()) 
    {
        Node* help=q.front(); //弹出队列
        q.pop();
        cout<<help->value<<" ";
        for(Node* t:help->nexts){ //遍历当前节点的邻接节点
            if(set.find(t)==set.end()){ //如果不在哈希表，则入队并记录
                q.push(t);
                set.emplace(t);
            }
        }
    }
    
}
//深度优先遍历 利用栈（可以用递归）
void dfs(Node* node)
{
	if(node == NULL)	return;
	stack<Node*> s;
	unordered_set<Node*> set;
	s.push(node); 
	set.insert(node);
	cout<<node->value<<" "; 				//第一个元素直接输出 
	while(!s.empty())
	{
		Node* help = s.top();
		s.pop();
		for(auto tmp : help->nexts)
		{
			if(set.find(tmp) == set.end())	//该节点如果没有遍历过
			{
				s.push(help);				//把当前节点压回栈
				s.push(tmp);				//把第一个找到的邻接节点压入栈，并记录
				set.insert(tmp);
				cout<<tmp->value<< " ";
				break;						//一次只找一个 
			}
		} 
	}
} 

int main(){
   
	vector<vector<int> > matrix= {{12,1,2},
								  {13,1,3},
								  {14,1,4},
								  {9,2,7},
								  {10,7,3},
								  {8,3,5},
								  {10,4,6}};
	Graph graph = createGraph(matrix);

	//test ：某节点所指向的节点 
	cout<<"1所指向：";
	Node* testnode = graph.nodes[1];
    

	for(auto n : testnode->nexts)
	 	cout<< n->value<<"、";
    cout<<endl;
	cout<<"2所指向：";	
	Node* testnode2 = graph.nodes[2];
    

	for(auto n : testnode2->nexts)
	 	cout<< n->value<<"、"; 	
	//test ：输出所有节点与边  	
	cout<<endl<<"-----------------------------------------------"<<endl ;
	cout<<"所有节点为： "<<endl ; 
	unordered_map<int,Node*>::iterator ite1 = graph.nodes.begin();
	while(ite1 != graph.nodes.end())
	{
	 	cout << "节点: "<<(ite1)->second->value<<"、";
		//cout << "节点: "<<(ite1)->first<<"、";
	 	ite1++;
	}
	cout<<endl<<"-----------------------------------------------"<<endl ;
	cout<<"节点与边为： "<<endl ;
	unordered_set<Edge*>::iterator ite = graph.edges.begin();
	while(ite != graph.edges.end())
	{
	 	cout << "边权为 "<<(*ite)->weight<<"    ";
	 	cout<<(*ite)->from->value <<"---->"<<(*ite)->to->value<<endl; 
	 	ite++;
	}
	
	
	Node *node = graph.nodes[1];
	cout<<endl<<"-----------------------------------------------"<<endl ;
	cout<<"宽度优先遍历bfs： "<<endl;
	bfs(node);
	
	
	
	
	cout<<endl<<"-----------------------------------------------"<<endl ;
	cout<<"深度优先遍历dfs： "<<endl;
	dfs(node);
	
	return 0;

}