#include<iostream>
#include<queue>
using namespace std;
// 二叉树的结点结构体，包含数据域和左右子树指针
struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
  // 构造函数，初始化数据域和子树指针
  TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

// 根据中序遍历和后序遍历构建二叉树的函数，参数为中序遍历数组，后序遍历数组，数组的长度
TreeNode* buildTree(int inorder[], int postorder[], int n) {
  // 如果数组为空，返回空指针
  if (n == 0) return NULL;
  // 取后序遍历数组的最后一个元素作为根结点的数据
  int rootData = postorder[n - 1];
  // 创建根结点
  TreeNode* root = new TreeNode(rootData);
  // 在中序遍历数组中找到根结点的位置
  int i = 0;
  while (i < n && inorder[i] != rootData) i++;
  // 递归地构建左子树和右子树
  root->left = buildTree(inorder, postorder, i);
  root->right = buildTree(inorder + i + 1, postorder + i, n - i - 1);
  // 返回根结点
  return root;
}

// 输出二叉树的右视图的函数，参数为根结点
void printRightView(TreeNode* root) {
  // 如果根结点为空，返回
  if (root == NULL) return;
  // 创建一个队列，用于层次遍历
  queue<TreeNode*> q;
  // 将根结点入队
  q.push(root);
  // 输出右视图的标志
  cout << "R: ";
  // 当队列不为空时，循环
  while (!q.empty()) {
    // 取出当前层的结点个数
    int size = q.size();
    // 遍历当前层的结点
    for (int i = 0; i < size; i++) {
      // 取出队首的结点
      TreeNode* node = q.front();
      q.pop();
      // 如果是当前层的最后一个结点，输出其数据
      if (i == size - 1) {
        if(node->left==nullptr&&node->right==nullptr&&q.empty()){
            cout<<node->data ;
        }
        else{
            cout << node->data << " ";
        }
        
      }
      // 如果有左子树，将其入队
      if (node->left) q.push(node->left);
      // 如果有右子树，将其入队
      if (node->right) q.push(node->right);
    }
  }
  // 输出换行符
  cout << endl;
}

// 输出二叉树的左视图的函数，参数为根结点
void printLeftView(TreeNode* root) {
  // 如果根结点为空，返回
  if (root == NULL) return;
  // 创建一个队列，用于层次遍历
  queue<TreeNode*> q;
  // 将根结点入队
  q.push(root);
  // 输出左视图的标志
  cout << "L: ";
  // 当队列不为空时，循环
  while (!q.empty()) {
    // 取出当前层的结点个数
    int size = q.size();
    // 遍历当前层的结点
    for (int i = 0; i < size; i++) {
      // 取出队首的结点
      TreeNode* node = q.front();
      q.pop();
      // 如果是当前层的第一个结点，输出其数据
      if (i == 0) {
        if(node->left==nullptr&&node->right==nullptr&&q.empty()){
            cout<<node->data ;
        }
        else{
            cout << node->data << " ";
        }
      }
      // 如果有左子树，将其入队
      if (node->left) q.push(node->left);
      // 如果有右子树，将其入队
      if (node->right) q.push(node->right);
    }
  }
  // 输出换行符
  cout << endl;
}

// 主函数，用于测试
int main() {
    int n;
    cin>>n;
    int inorder[n],postorder[n];
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    for(int i=0;i<n;i++){
        cin>>postorder[i];
    }
  // 构建二叉树
  TreeNode* root = buildTree(inorder, postorder, n);
  // 输出右视图
  printRightView(root);
  // 输出左视图
  printLeftView(root);
  // 返回0，表示程序正常结束
  return 0;
}



// #include<iostream>
// #include<vector>
// using namespace std;
// vector<vector<int>>yue(100);
// vector<int> wap(vector<int>a,int begin,int end)
// {
// 	vector<int>l(a.begin()+begin,a.begin()+end);
// 	return l;
// }
// void find(vector<int>arr1,vector<int>arr2,int deep)
// {
// 	if(arr1.empty()||arr2.empty())
//     {
//         return ;
//     }
// 	int root=arr2[arr2.size()-1];
// 	int index;
// 	for(int i=0;i<arr1.size();i++)
// 	{
// 		if(arr1[i]==root)index=i;
// 	}
// 	yue[deep].push_back(root);
// 	if(index>0){
//         find(wap(arr1,0,index),wap(arr2,0,index),deep+1);
//     }
// 	if(index+1<arr1.size()&&index+1<arr2.size())
//     {
//         find(wap(arr1,index+1,arr1.size()),wap(arr2,index,arr2.size()-1),deep+1);
//     }
// }
// int main()
// {
// 	vector<int>a;
// 	vector<int>b;
// 	int num;cin>>num;
// 	int y;
// 	for(int i=0;i<num;i++)
// 	{
// 		cin>>y;a.push_back(y);
// 	}
// 	for(int i=0;i<num;i++)
// 	{
// 		cin>>y;b.push_back(y);
// 	}
// 	int deep=0;
// 	find(a,b,deep);
// 	cout<<"R: "; cout<<yue[0][0];
// 	for(int i=1;i<100;i++)
// 	{
// 		if(yue[i].empty())break;
// 		else cout<<" "<<yue[i].back();
// 	}
// 	cout<<endl;
// 	cout<<"L: "; cout<<yue[0][0];
// 	for(int i=1;i<100;i++)
// 	{
// 		if(yue[i].empty())break;
// 		else cout<<" "<<yue[i].front();
// 	}
// }



// #include<iostream>
// #include<algorithm>
// #include<map>
// #include<vector>
// #include<string>
// #include<set>
// #include<math.h>
// #include<stdio.h>
// #include<stack>
// #include<queue>
// //#include<bits/stdc++.h>
// using namespace std;
 
// int a[25];
// int b[25];
// vector<int>dep[25];
// int maxdepth = 0;
 
// void xp(int num, int st, int en, int depth)
// {
// 	if (st > en)
// 	{
// 		return;
// 	}
// 	if (maxdepth < depth)
// 	{
// 		maxdepth = depth;
// 	}
// 	dep[depth].push_back(b[num]);
// 	int i = st;
// 	for (; i <= en; i++)
// 	{
// 		if (a[i] == b[num])
// 		{
// 			break;
// 		}
// 	}
// 	xp(num - 1 - (en - i), st, i - 1, depth + 1);
// 	xp(num - 1, i + 1, en, depth + 1);
// 	return;
// }
 
// int main()
// {
// 	int n;
// 	cin >> n;
// 	for (int i = 1; i <= n; i++)
// 	{
// 		cin >> a[i];
// 	}
// 	for (int i = 1; i <= n; i++)
// 	{
// 		cin >> b[i];
// 	}
// 	xp(n, 1, n, 1);
	
// 	cout << "R: " << dep[1][0];
// 	for (int i = 2; i <= maxdepth; i++)
// 	{
// 		cout << " " << dep[i].back();
// 	}
// 	cout << endl;
// 	cout << "L: " << dep[1][0];
// 	for (int i = 2; i <= maxdepth; i++)
// 	{
// 		cout << " " << dep[i].front();
// 	}
// 	return 0;
// }