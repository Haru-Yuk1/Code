#include <iostream>
#include<algorithm>
#include<cmath>
#include <queue> 
using namespace std;

struct node {
	int date;
	char info;
	node* left;
	node* right;
};

//以递归的方式构建一棵树
void createTree(node*& t) {
	char str;
	cin >> str;
	if (str == '#') {
		t = NULL;
	}
	else {
		t = new node;//为t开辟空间
		t->info = str;
		createTree(t->left);
		createTree(t->right);
	}
}

//树的深度
int depth(node* root) {
	if (root == nullptr) {
		return 0;
	}
	int left = depth(root->left);
	int right = depth(root->right);
	return max(left, right) + 1;
}

//打印一棵树满二叉树，只能打印满二叉树，节点数目最好不要超过10
void print(node*& root) {
	//存放打印的二叉树
	char str[10][100] = {};
	queue<node*> q;
	int h = depth(root);
	q.push(root);
	int index = 0;
	while (!q.empty()) {
		int size = q.size();
		//存放每一层的节点
		vector<char> list;
		for (int i = 0; i < size; i++) {
			node* temp = q.front();
			q.pop();
			list.push_back(temp->info);
			//cout << temp->info;
			if (temp->left != nullptr) {
				q.push(temp->left);
			}
			if (temp->right != nullptr) {
				q.push(temp->right);
			}	
		}
		bool flag = true;
		int j = 0;
		//打印前面部分空白
		while (j <= 2*h-1-index) {
			str[index][j] = ' ';
			j++;
			
		}
		//保持第一行居中
		if (index == 0) {
			for (int m = 0; m < h - 2; m++) {
				str[index][j++] = ' ';
			}
		}
		
		for (int k = 0; k < list.size(); k++) {
			//如果是一层最后一个节点
			if (k == list.size() - 1) {
				str[index][j++] = list[k];
			}
			else {
				//相邻左右子节点
				if (k % 2 == 0) {
					str[index][j++] = list[k];
					for (int l = 0; l < 3 + 2 * (h - index/2-1); l++) {
						str[index][j++] = ' ';
					}
				}
				else {
					str[index][j++] = list[k];
					str[index][j++] = ' ';
				}	
			}
		}
		
		index+=2;
		//cout << endl;
	}
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 1) {
			for (int j = 0; j < 100; j++) {
				str[i][j] = ' ';
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 100; j++) {
				if (str[i][j] - '0' >= 0 && str[i][j] - '0' <= 9 && i < 2*h -2) {
					str[i + 1][j - 1] = '/';
					str[i + 1][j + 1] = '\\';
				}
				
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 100; j++) {
				cout << str[i][j];
		}
		cout << endl;
	}
}

int main() {
	node* T;
	createTree(T);
	cout << "树的深度：" << depth(T) << endl;
	print(T);
	return 0;
}
