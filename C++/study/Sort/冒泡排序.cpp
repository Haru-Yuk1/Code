#include<iostream>
#include<vector>
using namespace std;
void swap(int* a,int* b){
    int* temp=a;
    a=b;
    b=temp;
}

vector<int> BubbleSort(vector<int> arr){
    if(arr.empty()||arr.size()<2){ //当arr为空,或只有一个元素
        return arr;
    }
    for(int i=0;i<arr.size()-1;i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}
int main(){
    vector<int> arr={1,3,5,4,2};
    arr=BubbleSort(arr);
    for(auto res:arr){
        cout<<res;
    }
}