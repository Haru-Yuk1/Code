#include<iostream>
using namespace std;
struct Queue
{
    int data[50];
    int front;
    int rear;
    Queue():front(0),rear(0){}
};
bool isEmpty(Queue Q){
    if(Q.rear==Q.front){
        return true;
    }
    else{
        return false;
    }
}
int main(){

}