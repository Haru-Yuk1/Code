#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode():val(0),right(nullptr),left(nullptr){}
    TreeNode(int x):val(x),right(nullptr),left(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right ):val(x),left(left),right(right){}
};

TreeNode* PreOrderDeSerialize(string s)
{
    if (s.empty())
        return nullptr;
    if (s[0] == '0')
    {
        s = s.substr(1);    //从1开始截取字符，相当于删除第一个元素
        return nullptr;
    }
    TreeNode* node = new TreeNode(s[0]-'0');
    s = s.substr(1);
    node->left = PreOrderDeSerialize(s);
    node->right = PreOrderDeSerialize(s);
    return node;
}
//使用递归的先序、中序、后序
void PreOrderRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    cout<<head->val<<" ";
    PreOrderRecur(head->left);
    PreOrderRecur(head->right);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    string s;
    for(int i=0;i<nums.size();i++){
        s.push_back(nums[i]);
    }
    TreeNode* head=PreOrderDeSerialize(s);
    PreOrderRecur(head);

}
