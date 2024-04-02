#include<iostream>
#include<algorithm>
using namespace std;
#define MAXSIZE 50

//最大堆
struct MaxHeap
{
    int *arr; //存储堆元素的数组
    int size; //当前已存储的元素个数
    int capacity; //当前存储的容量
    
};
void InitHeap(MaxHeap* heap,int size){
    //orginal：原数据  size：数据个数  heap：堆
    int capacity=MAXSIZE>size?MAXSIZE:size;
    heap->arr=new int[capacity];
    heap->capacity=capacity;
    heap->size=0;
}
/*向下调整将当前的节点和子节点调整成最大堆*/
void adjustDown(MaxHeap &heap, int index) { 
    int cur=heap.arr[index];//当前待调整的节点
	int parent,child;
    /*判断否存在大于当前节点子节点，如果不存在 ，则堆本身是平衡的，不需要调整；
    如果存在，则将最大的子节点与之交换，交换后，如果这个子节点还有子节点，
    则要继续按照同样的步骤对这个子节点进行调整*/
	for(parent=index; (parent*2+1)<heap.size; parent=child) {
        child=parent*2+1;   
        
        //取两个子节点中的最大的节点
        
        if(((child+1)<heap.size)&&(heap.arr[child]<heap.arr[child+1])) {
        	child++;
		}
        
        //判断最大的节点是否大于当前的父节点
        if(cur>=heap.arr[child]) {//不大于，则不需要调整，跳出循环
             break;
        }else {//大于当前的父节点，进行交换，然后从子节点位置继续向下调整
             heap.arr[parent]=heap.arr[child];
             heap.arr[child]=cur;
        }
    }
}
/*将当前的节点和父节点调整成最大堆*/
void adjustUp(MaxHeap &heap, int index) {
    if(index<0 || index >= heap.size) {//大于堆的最大值直接 return
    	return;
    }

    while(index>0){	
        int temp = heap.arr[index];
        int parent = (index - 1) / 2;
        
        if(parent >= 0){//如果索引没有出界就执行想要的操作
        	if(temp > heap.arr[parent]){ //如果比父亲大，则交换，并将index上移
                heap.arr[index] = heap.arr[parent];
                heap.arr[parent] = temp;
                index = parent;
        	} else {//如果已经比父亲小 直接结束循环
        		break;
        	}
        } else {//越界结束循环
        	break;
        }
    }
}

/*判断堆是否为空*/
bool isEmpty(MaxHeap &heap){
	if(heap.size<1) return true;
		return false;
}
/* 从最后一个父节点(size/2-1 的位置)逐个往前调整所有父节点（直到根节点）,
确保每一个父节点都是一个最大堆，最后整体上形成一个最大堆 */
// 同时也可用来快速建堆
void Heapify(MaxHeap &heap){
    for(int i=heap.size/2-1; i>=0; i--){
    	adjustDown(heap, i);
    }
}
//朴素建堆
void BuildHeap(MaxHeap& heap){
    for(int i=1;i<heap.size;i++){
        adjustUp(heap,i);
    }
}
/*最大堆尾部插入节点，同时保证最大堆的特性*/
void HeapInsert(MaxHeap &heap, int value) {
	if (heap.size == heap.capacity) {
		return;
	}
    int index = heap.size;
    heap.arr[heap.size++] = value;
    adjustUp(heap, index);
}

/* 删除堆顶元素，获取堆顶的数据*/
int pop(MaxHeap &heap) {
    //堆为空返回
    if (isEmpty(heap)) return ;
    int value =heap.arr[0];
    //把最后一个元素放到堆顶，然后向下调整
    heap.arr[0] = heap.arr[--heap.size];
    adjustDown(heap, 0);// 向下执行堆调整
    return value;
}

// //求结点数为n的二叉树的深度
// int depth(int n) {
// 	assert(n >= 0);

// 	if (n>0) {
// 		int m = 2;
// 		int hight = 1;
// 		while (m < n + 1) {
// 			m *= 2;
// 			hight++;
// 		}
// 		return hight;
// 	} else {
// 		return 0;
// 	}
// }

// //打印堆
// void HeapPrint(Heap* php) {
// 	assert(php);
// 	//按照物理结构进行打印
// 	int i = 0;
// 	for (i = 0; i < php->size; i++)
// 	{
// 		printf("%d ", php->a[i]);
// 	}
// 	printf("\n");
// 	//按照树形结构进行打印
// 	int h = depth(php->size);
// 	int N = (int)pow(2, h) - 1;//与该二叉树深度相同的满二叉树的结点总数
// 	int space = N - 1;//记录每一行前面的空格数
// 	int row = 1;//当前打印的行数
// 	int pos = 0;//待打印数据的下标
// 	while (1) {
// 		//打印前面的空格
// 		int i = 0;
// 		for (i = 0; i < space; i++) {
// 			printf(" ");
// 		}
// 		//打印数据和间距
// 		int count = (int)pow(2, row - 1);//每一行的数字个数
// 		while (count--)//打印一行
// 		{
// 			printf("%02d", php->a[pos++]);//打印数据
// 			if (pos >= php->size)//数据打印完毕
// 			{
// 				printf("\n");
// 				return;
// 			}
// 			int distance = (space + 1) * 2;//两个数之间的空格数
// 			while (distance--)//打印两个数之间的空格
// 			{
// 				printf(" ");
// 			}
// 		}
// 		printf("\n");
// 		row++;
// 		space = space / 2 - 1;
// 	}
// }

// /*销毁堆*/
// void destroy(Heap &heap){
//     if(heap.arr) delete[] heap.arr;
   
//     heap->arr = NULL;//及时置空
//     heap->size = 0;//元素个数置0
//     heap->capacity = 0;//容量置0  
// }
// int main(){
//     int arr[]={1,2,3,4,5};
//     MaxHeap* heap;
//     InitHeap(heap,5);
//     HeapInsert(heap,1);
//     HeapInsert
// }