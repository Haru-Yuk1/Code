#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<float> sample(n);
    for(int i=0;i<n;i++){
        cin>>sample[i];
    }
      

    float average=0;
    for(int i=0;i<n;i++){
        average+=sample[i]/5;
    }

}