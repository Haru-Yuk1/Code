#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Program{
    public:
        int start;
        int end;
        Program(int start,int end){
            this->end=end;
            this->start=start;
        }
};
bool compare(Program* o1,Program* o2){
    return o1->end<o2->end;
}
int bestArrange(vector<Program*> programs,int timePoint){
    sort(programs.begin(),programs.end(),compare);
    int result=0;
    //从左往右依次遍历所有的会议
    for(int i=0;i<programs.size();i++){
        if(timePoint<=programs[i]->start){
            result++;
            timePoint=programs[i]->end;
        }

    }
    return result;
}
int main(){
    Program* p1=new Program(6,9);
    Program* p2=new Program(7,8);
    Program* p3=new Program(8,9);
    Program* p4=new Program(10,19);
    Program* p5=new Program(10,11);
    Program* p6=new Program(12,13);
    vector<Program*> Programs(6);
    Programs[0]=p1;
    Programs[1]=p2;
    Programs[2]=p3;
    Programs[3]=p4;
    Programs[4]=p5;
    Programs[5]=p6;
    
    int res=bestArrange(Programs,6);
    cout<<res;
}