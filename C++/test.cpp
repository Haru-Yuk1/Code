#include <iostream>
#include <map>
#include <vector>
#include<list>
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
int main() {
    list<int> l1={1,2,3,4};
    list<int> l2={1,2,3,4};
    list<TreeNode*> *l3=new list<TreeNode*>();
    list<TreeNode*> *l4=new list<TreeNode*>();
    
    cout<<&l1<<" "<<&l2<<endl;
    cout<<&l3<<" "<<&l4<<endl;
    if(l1==l2) cout<<"yes";
    if(l3==l4) cout<<"yes";
}
