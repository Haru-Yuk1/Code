#include <iostream> 
#include <string> 
#include <unordered_map> 
#include <cmath> 
using namespace std;

int H[10010],count;//数组H用来存放堆 count计数
void creatminHeap(int x)//建造小顶堆
{
    H[++count]=x;
    int t=count;
    while(t>1&&(H[t/2]>H[t]))//判断是否比父结点（数组下标/2）要小
    {
        H[t]=H[t/2];
        H[t/2]=x;//和父结点相交换
        t/=2;//记录当前下下标位置进入下一层循环
    }
    H[t]=x;
}
int main()
{
    int N,M,x,y;
   

    cin>>N>>M;
    count=0;
    unordered_map<int,int>p;//记录位置
    string s;
    for(int i=1;i<=N;i++)
    {
        cin>>x;
        creatminHeap(x);//创建小顶堆
    }
    for(int i=1;i<=N;i++)
    {
        p[H[i]]=i;//这个p数字就是来记录数组的下标 判断是根结点还是父子结点还是兄弟结点
    }
    //下面运用的就基本上是字符串的知识了
    for(int i=0;i<M;i++)
    {
        cin>>x;
        cin>>s;
        if(s[0]=='a')
        {
            cin>>y;
            getline(cin,s);
            if(p[x]/2==p[y]/2)
            {
                cout<<"T"<<endl;
            }
            else
            {
                cout<<"F"<<endl;
            }
        }
        else
        {
            cin>>s;
            cin>>s;
            if(s[0]=='r')
            {
                if(p[x]==1)
                {
                    cout<<"T"<<endl;
                }
                else
                {
                    cout<<"F"<<endl;
                }
            }
            else if(s[0]=='p')
            {
                cin>>s;
                cin>>y;
                if(p[x]==p[y]/2)cout<<"T"<<endl;
                else cout<<"F"<<endl;
            }
            else
            {
                cin>>s;
                cin>>y;
                if(p[x]/2==p[y])cout<<"T"<<endl;
                else cout<<"F"<<endl;
            }
        }
    }  
}
