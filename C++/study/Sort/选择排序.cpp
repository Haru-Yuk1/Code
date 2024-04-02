#include<iostream>
#include<vector>
using namespace std;

void swap(int* a,int* b){
    int* temp=a;
    a=b;
    b=temp;
}

vector<int> SelectionSort(vector<int> arr){
    if(arr.empty()||arr.size()<2){ //当arr为空,或只有一个元素
        return arr;
    }
    for(int i=0;i<arr.size();i++){
        int minIndex=i;
        for(int j=i+1;j<arr.size();j++){
            minIndex=arr[j]<arr[minIndex]?j:minIndex;  //每次找到最小的元素

        }
        swap(arr[minIndex],arr[i]);
    }   
    return arr;
}
int main(){
    vector<int> arr(6);
    for(int i=0;i<6;i++){
        cin>>arr[i];
    }
    arr=SelectionSort(arr);
    for(int i=0;i<6;i++){
        cout<<arr[i];
    }

}