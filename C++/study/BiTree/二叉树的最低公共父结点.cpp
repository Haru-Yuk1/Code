#include<iostream>
#include<unordered_map>
#include<unordered_set>
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
// o1和o2一定属于head为头的树，返回o1和o2的最低公共祖先
void process(TreeNode* head,unordered_map<TreeNode*,TreeNode*> fatherMap){
    if(head==nullptr){
        return;
    }
    fatherMap.emplace(head->left,head);
    fatherMap.emplace(head->right,head);
    process(head->left,fatherMap);
    process(head->right,fatherMap);
}
TreeNode* lowestCommonAncestor1(TreeNode* head,TreeNode* o1,TreeNode* o2){
    unordered_map<TreeNode*,TreeNode*> fatherMap;
    fatherMap.emplace(head,head);
    process(head,fatherMap);
    unordered_set<TreeNode*> set1;
    TreeNode* cur=o1;
    while (cur!=fatherMap[cur])
    {
        set1.emplace(cur);
        cur=fatherMap[cur];
    }
    set1.emplace(head);
    for (auto iter = set1.begin(); iter != set1.end(); ++iter) {
        cout << *iter << endl;
    }
    while(set1.find(o2)!=set1.end()){
        o2=fatherMap[o2];
    }
    return o2;
    
}


//最优解，分为两种情况，一种o1或o2是公共父结点，一种都不是要找相交
TreeNode* lowestCommonAncestor2(TreeNode* head,TreeNode* o1,TreeNode* o2){
    if(head==nullptr||head==o1||head==o2){// 当遇到空或o1或o2返回
        return head;
    }
    TreeNode* left=lowestCommonAncestor2(head->left,o1,o2); //从左子树获取信息，为空，o1,o2
    TreeNode* right=lowestCommonAncestor2(head->right,o1,o2);//从右子树获取信息，为空，o1,o2
    if(left!=nullptr&&right!=nullptr){ //当左或右都不为空，说明是第二种情况，那么此时的结点就是公共结点
        return head;
    }
    return left!=nullptr?left:right;//当左或右有一个不为空，返回不空的，都为空，返回空。
}

int main(){
    TreeNode* head=new TreeNode(1);
    TreeNode* temp1=new TreeNode(2);
    TreeNode* temp2=new TreeNode(3);
    TreeNode* temp3=new TreeNode(4);
    TreeNode* temp4=new TreeNode(5);
    TreeNode* temp5=new TreeNode(6);
    TreeNode* temp6=new TreeNode(7);
    TreeNode* temp7=new TreeNode(8);
    head->left=temp1;
    head->right=temp2;
    temp1->left=temp3;
    temp1->right=temp4;
    temp2->left=temp5;
    temp2->right=temp6;
    temp6->right=temp7;
    TreeNode* p=head;
    TreeNode* ans1=lowestCommonAncestor1(head,temp7,temp5);
    TreeNode* ans2=lowestCommonAncestor2(head,temp7,temp5);
    cout<<ans1->val<<" "<<ans2->val;
}