#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Binary_Search(vector<int> L, int key){
	int low = 0, high = L.size() - 1, mid;
	while(low <= high){
		mid = (low + high)/2;	//取中间位置
		if(L[mid] == key){
			return mid;	//查找成功返回所在位置
		}else if(L[mid] > key){
			high = mid - 1;	//从前半部分继续查找
		}else{
			low = mid + 1;	//从后半部分继续查找
		}
	}
	return -1;	//查找失败，返回-1
}

int main(){
    int n;
    cin>>n;
    vector<int> L(n);
    for(int i=0;i<n;i++){
        cin>>L[i];
    }
    sort(L.begin(),L.end());
    int num_queries;
    cin>>num_queries;
    for (int i = 0; i < num_queries; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> subarray(L.begin() + b, L.begin() + c + 1);
        int targetIndex = Binary_Search(subarray, a);

        if (targetIndex != -1) {
            cout << b + targetIndex << endl;
        } else {
            cout << -1 << endl;
        }
    }
}