#include<iostream>
#include<string>
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
void PreOrderSerialize(TreeNode* head){
    if(head==nullptr){
        cout<<"#";
    }
    else{
        cout<<head->val;
        PreOrderSerialize(head->left);
        PreOrderSerialize(head->right);
    }
}
void InOrderSerialize(TreeNode* head){
    if(head==nullptr){
        cout<<"#";
    }
    else{
        
        PreOrderSerialize(head->left);
        cout<<head->val;
        PreOrderSerialize(head->right);
    }
}
void PosOrderSerialize(TreeNode* head){
    if(head==nullptr){
        cout<<"#";
    }
    else{
        
        PreOrderSerialize(head->left);
        PreOrderSerialize(head->right);
        cout<<head->val;
    }
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
    TreeNode* node = new TreeNode(s[0]-'0');
    s = s.substr(1);
    node->left = PreOrderDeSerialize(s);
    node->right = PreOrderDeSerialize(s);
    return node;
}
TreeNode* PosOrderDeSerialize(string &s){
    s.reserve();
    if (s.empty())
        return nullptr;
    if (s[0] == '#')
    {
        s = s.substr(1);
        return nullptr;
    }
    TreeNode* node = new TreeNode(s[0]-'0');
    s = s.substr(1);
    node->left = PreOrderDeSerialize(s);
    node->right = PreOrderDeSerialize(s);
    return node;
}
void PreOrderRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    cout<<head->val<<" ";
    PreOrderRecur(head->left);
    PreOrderRecur(head->right);
}
void PosOrderRecur(TreeNode* head){
    if(head==nullptr){
        return;
    }
    PosOrderRecur(head->left);
    PosOrderRecur(head->right);
    cout<<head->val<<" ";
}
int main(){
    TreeNode* head=new TreeNode(1);
    TreeNode* temp1=new TreeNode(2);
    TreeNode* temp2=new TreeNode(3);
    TreeNode* temp3=new TreeNode(4);
    TreeNode* temp4=new TreeNode(5);
    TreeNode* temp5=new TreeNode(6);
    TreeNode* temp6=new TreeNode(7);
    head->left=temp1;
    head->right=temp2;
    temp1->left=temp3;
    temp1->right=temp4;
    temp2->left=temp5;
    temp2->right=temp6;
    TreeNode* p=head;
    cout<<"——————先序序列化——————"<<endl;
    PreOrderSerialize(p);
    cout<<endl;
    cout<<"——————中序序列化——————"<<endl;
    InOrderSerialize(p);
    cout<<endl;
    cout<<"——————后序序列化——————"<<endl;
    PosOrderSerialize(p);
    PosOrderRecur(p);
    cout<<endl;
    string preorder="124##5##36##7##";
    string inorder="24##5##136##7##";
    string posorder="24##5##36##7##1";
    TreeNode* newp1=PreOrderDeSerialize(preorder);
    PreOrderRecur(newp1);
    TreeNode* newp2=PreOrderDeSerialize(posorder);
}