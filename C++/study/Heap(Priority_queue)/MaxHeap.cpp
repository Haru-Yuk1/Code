#include<iostream>
#include<vector>
using namespace std;
//用vector数组作底层结构
struct MaxHeap{
    vector<int> arr;
    int size;
    MaxHeap():arr({}),size(0){}
    MaxHeap(vector<int> arr):arr(arr),size(arr.size()){}
};
//上调操作
void SiftUp(MaxHeap* heap,int index){
    //如果不满足
    if(heap->size==0||index<0||index>heap->size){
        return;
    }
    //定义一个变量存储当前结点值
    int temp=heap->arr[index];
    //当index没越界且当前节点大于父节点，值往上移
    while (index>0&&temp>heap->arr[(index-1)/2])
    {
        heap->arr[index]=heap->arr[(index-1)/2];
        index=(index-1)/2;
    }
    //将最上面的结点令为存储的结点值
    heap->arr[index]=temp;
}
//下调操作
void SiftDown(MaxHeap* heap,int index){
    int cur=heap->arr[index];//当前待调整的节点
	int parent,child;
    /*判断否存在大于当前节点子节点，如果不存在 ，则堆本身是平衡的，不需要调整；
    如果存在，则将最大的子节点与之交换，交换后，如果这个子节点还有子节点，
    则要继续按照同样的步骤对这个子节点进行调整*/
	for(parent=index; (parent*2+1)<heap->size; parent=child) {
        child=parent*2+1;   
        //取两个子节点中的最大的节点
        if(((child+1)<heap->size)&&(heap->arr[child]<heap->arr[child+1])) {
        	child++;
		}
        //判断最大的节点是否大于当前的父节点
        if(cur>=heap->arr[child]) {//不大于，则不需要调整，跳出循环
             break;
        }else {//大于当前的父节点，进行交换，然后从子节点位置继续向下调整
             heap->arr[parent]=heap->arr[child];
             heap->arr[child]=cur;
        }
    }
}

int main(){

}