#include<iostream>
#include<vector>
using namespace std;
void swap(int* a,int* b){
    int* temp=a;
    a=b;
    b=temp;
}

vector<int> InsertionSort(vector<int> arr){
    if(arr.size()<2){
        return arr;
    }
    for(int i=1;i<arr.size();i++){
        for(int j=i;j>0;j--){
            if(arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);                
            }
        }
    }
    return arr;
}
vector<int> BinaryInsertionSort(vector<int> arr){
    if(arr.size()<2){
        return arr;
    }
    for(int i=1;i<arr.size();i++){
        // 保存当前元素和其位置
        int key = arr[i];
        int pos = i;
        // 在已排序的部分（0 ~ i-1）中使用二分查找找到插入位置
        int low = 0;
        int high = i - 1;
        //进行折半查找
        while (low <= high) {
            // 计算中间位置
            int mid = (low + high) / 2;
            // 如果当前元素小于中间元素，说明插入位置在左半部分
            if (key < arr[mid]) {
                high = mid - 1;
            }
            // 如果当前元素大于等于中间元素，说明插入位置在右半部分
            else {
                low = mid + 1;
            }
        }
        // 将插入位置右边的元素都向右移动一位，为插入元素腾出空间
        for (int j = i; j > low; j--) {
            arr[j] = arr[j - 1];
        }
        // 将当前元素插入到找到的位置
        arr[low] = key;
    }
    return arr;
}
int main(){
    vector<int> arr={1,3,5,4,2};
    arr=InsertionSort(arr);
    for(auto res:arr){
        cout<<res;
    }
    cout<<endl;
    vector<int> arr2={1,3,5,4,2};
    arr2=BinaryInsertionSort(arr2);
    for(auto res:arr){
        cout<<res;
    }
}