#include<iostream>
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
int main(){
    TreeNode* head=new TreeNode();
    TreeNode* p=head;
    for(int i=1;i<5;i++){
        TreeNode * temp=new TreeNode(i);
        p->left=temp;
    }
}