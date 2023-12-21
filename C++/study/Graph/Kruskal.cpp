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
//自己实现类似并查集的功能,但没有并查集快
class MySets{
    public:
        unordered_map<Node*,list<Node*>*> setMap;    //定义一个哈希表记录节点和它所在集合
        MySets(list<Node*> nodes){
            list<Node*> *set;           //必须这样初始化，不然每个循环初始时地址相同
            for(auto cur :nodes){
                set=new list<Node*>();  //必须这样初始化，不然每个循环初始时地址相同
                set->push_back(cur);
                setMap.emplace(cur,set);
            }
        }
        bool isSameSet(Node* from,Node* to){
            list<Node*> *fromSet= setMap[from]; 
            list<Node*> *toSet =setMap[to];
            return fromSet==toSet;
        }
        void Union(Node* from,Node* to){
            list<Node*> *fromSet= setMap[from];
            list<Node*> *toSet =setMap[to];
            for(auto toNode:*toSet){         //遍历去点的集合内所有的点，将这些点放入来点的集合，再将去点的集合更新
                fromSet->push_back(toNode);
                setMap[toNode]=fromSet;
            }
        }
};
//重载堆的比较器
struct  cmp
{
    bool operator()(Edge* a,Edge* b){
        return a->weight>b->weight;
    }
};
//k算法不使用并查集
void KruskalMST(Graph graph){
    list<Node*> tmp;
    for(auto node:graph.nodes){
        tmp.push_back(node.second);
    }
    MySets* mysets=new MySets(tmp);
    //用小顶堆来存储边，并通过边的权重比较，这样能先输出权重小的
    priority_queue<Edge*,vector<Edge*>,cmp> priorityQueue;
    for(auto edge:graph.edges){
        priorityQueue.emplace(edge);
    }
    unordered_set<Edge*> result;  //可以改写一下用集合存储然后返回result
    while(!priorityQueue.empty()){
        Edge* edge=priorityQueue.top();
        priorityQueue.pop();
        if(!mysets->isSameSet(edge->from,edge->to)){
            cout<<"该边的来点的值:"<<edge->from->value<<"该边的去点的值:"<<edge->to->value<<"该边权重:"<<edge->weight<<endl;
            mysets->Union(edge->from,edge->to);
        }
    }
    //return result;
}


//使用并查集
template <class T> //
class UnionFind_easy
{
	unordered_map<T, unordered_set<T>*>* setmap;//每个节点Node*   对应其所在的  Node* 集合 
 
public:
	UnionFind_easy(){
		setmap = new unordered_map<T, unordered_set<T>*>;
	}
	UnionFind_easy(unordered_map<int,T>* m):UnionFind_easy<T>(){
		for (auto& x :(*m)) {
			unordered_set<T>* s = new unordered_set<T>;
			s->insert(x.second);
			setmap->emplace(x.second, s);
		}
	}
	~UnionFind_easy() {
		unordered_set<unordered_set<T>*> d;//防止重复删除（并查集  setmap的map值中 会有重复的集合）
		for (auto& x : (*setmap)) {
			if (d.find(x.second) == d.end()) {
				d.emplace(x.second);
				delete x.second;
			}
		}		
		delete setmap;	
	}
	bool IsSameSet(T n1, T n2) {
		return setmap->operator[](n1) == setmap->operator[](n2);
	}
	void Union(T n1, T n2) {
		auto m = *setmap;
		unordered_set<T>* s1 =m[n1];	//假设 S1 {n1 n5}  n1->S1  n5->S1
		unordered_set<T>* s2 = m[n2];  // S2 {n2 n4}	n2->S2  n4->S2
		//for (auto x = s2->begin(); x != s2->end(); x++)		
		//	s1->insert(*x);									//S1{n1 n2 n4 n5}		n1->S1  n5->S1					
		//setmap->erase(n2);									//n1->S1  n5->S1	n2->S1    but n5?
		/*修改*/
		for (auto& x :(*s2)) {//把 s2中的每个node* 都复制到s1 并在map中将其指向s1
			s1->insert(x);  
			setmap->operator[](x)= s1;
		}
		delete s2;
	}
};
void KruskalMST2(Graph graph){
    UnionFind_easy<Node*> U(&graph.nodes);
    //用小顶堆来存储边，并通过边的权重比较，这样能先输出权重小的
    priority_queue<Edge*,vector<Edge*>,cmp> priorityQueue;
    for(auto edge:graph.edges){
        priorityQueue.emplace(edge);
    }
    while(!priorityQueue.empty()){
        Edge* edge=priorityQueue.top();
        priorityQueue.pop();
        if(!U.IsSameSet(edge->from,edge->to)){
            cout<<"该边的来点的值:"<<edge->from->value<<"该边的去点的值:"<<edge->to->value<<"该边权重:"<<edge->weight<<endl;
            U.Union(edge->from,edge->to);
        }
    }
}
int main(){
    vector<vector<int> > matrix= {{7,1,2},{7,2,1},{2,1,3},{2,3,1},{10,1,4},{10,4,1},{100,2,5},{100,5,2}
    ,{11,2,4},{11,4,2},{4,3,4},{4,4,3}};
	Graph graph = createGraph(matrix);
    // unordered_set<Edge*> result=KruskalMST(graph);
    
    KruskalMST(graph);
    cout<<"使用并查集的"<<endl;
    KruskalMST2(graph);
    
}