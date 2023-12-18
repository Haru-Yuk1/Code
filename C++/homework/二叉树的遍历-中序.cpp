#include<iostream>
#include<string>
using namespace std;
struct TreeNode
{
    char val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(char s):val(s),right(nullptr),left(nullptr){}
    
};
void InOrderRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    InOrderRecur(head->left);
    cout<<head->val;
    InOrderRecur(head->right);
}
TreeNode* PreOrderDeSerialize(string& s)
{
    if (s.empty())
        return nullptr;
    if (s[0] == '#')
    {
        s = s.substr(1);
        return nullptr;
    }
    TreeNode* node = new TreeNode(s[0]);
    s = s.substr(1);
    node->left = PreOrderDeSerialize(s);
    node->right = PreOrderDeSerialize(s);
    return node;
}
int main(){
    string s;
    cin>>s;
    TreeNode* head= PreOrderDeSerialize(s);
    InOrderRecur(head);
}