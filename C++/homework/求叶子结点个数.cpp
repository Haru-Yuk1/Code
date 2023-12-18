#include<stdio.h>
#include<malloc.h>
#define len sizeof(struct BiTNode )

typedef struct BiTNode
{
    char data;  //数据域
    struct BiTNode *lchild;  //左孩子指针
    struct BiTNode *rchild;  //右孩子指针
}BiTNode,*BiTree;

void creat(BiTree &Tree);//构建二叉树
int countleaf(BiTree Tree);//求叶子结点个数
 
int main()
{
    BiTree Tree;
    creat(Tree);//创建二叉树
    printf("%d\n",countleaf(Tree)); //输入叶子节点个数
    return 0;
}

/* 请在这里填写答案 */

//创建二叉树
void creat(BiTree &Tree)
{
    char ch;
    scanf("%c", &ch); //输入一个字符
    if (ch == '#') //如果是'#'，表示空树
        Tree = NULL;
    else
    {
        Tree = (BiTree)malloc(sizeof(BiTNode)); //分配内存空间
        Tree->data = ch; //存储数据
        creat(Tree->lchild); //递归创建左子树
        creat(Tree->rchild); //递归创建右子树
    }
}

//叶子结点计数
int countleaf(BiTree Tree)
{
    if (!Tree) //如果树为空，返回0
        return 0;
    else if (!Tree->lchild && !Tree->rchild) //如果结点的左右孩子都为空，返回1
        return 1;
    else //否则，返回左右子树的叶子结点个数之和
        return countleaf(Tree->lchild) + countleaf(Tree->rchild);
}
