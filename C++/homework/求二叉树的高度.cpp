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

int Depth(BiTree Tree);//求深度

int main()
{
    BiTree Tree;
    creat(Tree);//创建二叉树
    printf("%d\n",Depth(Tree));
    return 0;
}
/* 请在这里填写答案 */
//构建二叉树
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

//求高度
int Depth(BiTree Tree)
{
    if (Tree == NULL) //如果树为空，返回0
        return 0;
    else
    {
        int left = Depth(Tree->lchild); //递归求左子树的高度
        int right = Depth(Tree->rchild); //递归求右子树的高度
        return (left > right ? left : right) + 1; //返回较大的高度加1
    }
}
