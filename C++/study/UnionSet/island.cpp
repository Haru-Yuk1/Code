#include<iostream>
#include<vector>
using namespace std;
//感染函数，用于将连接的一片岛都令为2
void infect(vector<vector<int>>& m,int i,int j,int N,int M){
    if(i<0||i>=N||j<0||j>=M||m[i][j]!=1){
        return;
    }
    //必须要对m进行引用，不然只能局部改值
    m[i][j]=2;
    infect(m,i+1,j,N,M); 
    infect(m,i-1,j,N,M);
    infect(m,i,j+1,N,M);
    infect(m,i,j-1,N,M);
    return;
}
int countIslands(vector<vector<int>>& m){
    if(m.empty()||m[0].empty()){
        return 0;
    }
    int res=0;
    int N=m.size();
    int M=m[0].size();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(m[i][j]==1){
                res++;
                infect(m,i,j,N,M);//将这点连接的点都感染
            }   
        }
    }
    return res;
}

int main(){
    vector<vector<int>> m1={{0,1,0,1,0,1},{1,1,1,1,0,1},{1,0,0,0,1,1},{0,0,1,0,0,0}};
    
    cout<<countIslands(m1)<<endl;
    return 0;
}