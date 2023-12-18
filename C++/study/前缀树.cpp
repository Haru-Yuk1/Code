#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#define num 26
using namespace std;

class TrieNode{
    public:
        int pass; //经过的次数
        int end; //结尾的次数
        TrieNode* nexts[num]; //设置字符串个数的最多前缀‘a~z’
        //如果字符特别多，用数组浪费空间：
        //也可以用哈希表unordered_map<char,TrieNode> nexts; char记录路，TrieNode表示路的下一个节点
        //TreeMap<> nexts;
        TrieNode():pass(0),end(0){
            //memset 函数用于设置nexts数组的初始值为0
            memset(nexts,0,sizeof(nexts)); 
        }

};

class TrieTree{
    private:
        TrieNode *root;
    public:
        TrieTree();
        ~TrieTree();
        void destroy(TrieNode *node);
        void insert(string word);
        int search(string word);
        void delete_word(string word);
        int prefixNumber(string pre);

};
// 构造函数
TrieTree::TrieTree(){
    root=new TrieNode();
}
//析构函数
TrieTree::~TrieTree(){
    destroy(root);
}
//删除整棵树
void TrieTree::destroy(TrieNode *root)
{
	if(root ==NULL)
		return;
	for(int i = 0; i < num; i++)
	{	//每个new出的数组需要删除
		destroy(root->nexts[i]);
	}
	delete root;
	root = NULL;
}
//插入函数
void TrieTree::insert(string word)
{
	if(&word==NULL)	//不能用word.empty()来写，不然不能加入“”的字符串							
		return;
	if(word.empty()){
		root->pass++;
	}
	TrieNode *node = root;
	int index = 0;
	for(int i = 0;i < word.size(); i++)
	{
		index = word[i] - 'a';					//将输入的字符转换为索引值a是0，b是1...
		if(node->nexts[index] == NULL)			//这条路未被创建
		{
			node->nexts[index] = new TrieNode();//创建路
		}
		node = node->nexts[index];				//指向新建的路
		node->pass++;							//经过+1
	}
	node->end++;								//最后再记录结束
	
}
//查找函数
int TrieTree::search(string word)
{
	if(&word==NULL) //不能用word.empty()来写，不然不能加入“”的字符串
		return 0;
	int index = 0;
	TrieNode *node = root;
	for(int i = 0;i < word.size();i++) //遍历这个字符串
	{
		index = word[i] - 'a';
		if(node->nexts[index]==NULL) //如果没有这条路则换回0
			return 0;
		node = node->nexts[index];
	}
	return node->end;
}


//删除函数
void TrieTree::delete_word(string word)
{
	if(search(word) == 0)		//先进行查找确定存在
		return;
	TrieNode *node = root;
	TrieNode *tmp = root;
	int index = 0;
	for(int i = 0;i < word.size();i++)
	{
		index = word[i] - 'a';
		tmp = node->nexts[index];			//使用中间变量记录当前节点的下一个节点
		if(--node->nexts[index]->pass == 0){	//如果将--pass后，节点的pass为0，表示以后的节点都不存在
			destroy(tmp);
			node->nexts[index]=NULL;
			break;		//释放
        }   
		else{
            node = tmp;							//当前节点移动到下一个节点
        }
    }
	node->end--;
}

int TrieTree::prefixNumber(string pre) 
{
	if(pre==""){
		return root->pass;
	}
	if(&pre==NULL) //不能用pre.empty()来写，不然不能加入“”的字符串
		return 0;
	
	TrieNode* node = root;
	
	int index = 0;
	for(int i = 0;i < pre.size();i++)
	{
		index = pre[i] - 'a';
		if(node->nexts[index] == NULL)	//不存在此前缀直接返回0个
			return 0;
		node = node->nexts[index];		
	}	return node->pass;
}


int main()
{

	TrieTree a;
	a.insert("");
	a.insert("");
	a.insert("abd");
	a.insert("abc");
	a.insert("abc");
	a.insert("bck");
    a.insert("ace");
	cout<<(a.search("")?"yes":"no")<<" 有几个:"<<a.search("")<<endl;
    
	a.delete_word("abc");
    
	// a.insert("abd");
	cout<<a.prefixNumber("")<<endl;
	return 0;
}

