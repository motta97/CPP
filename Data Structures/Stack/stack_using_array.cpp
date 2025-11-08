#include <iostream>
using namespace std;
template <typename T>
class stack_using_array{
    private:
    int size;
    T *p;
    int count = -1;
    public:
    stack_using_array(int s){
        this->size= s;
        p = new T[size];
    }
    bool isFull(){
        return count==size-1;
    }
    bool isEmpty(){
        return count==-1;
    }
    void push(int x){
        if(!isFull()){
        count++;
        p[count]=x;
        }
        else cout<<"Stack Overflow!"<<endl;

    }
    T pop(){
        if(!isEmpty()){
            count--;
            return p[count+1];
        }
        return '0';
    }
    void peek(int index){
        if(!isEmpty()&&index<=count){
            count=index;
        }
        else cout<<"Index out of range! "<<endl;
    }
    int stackTop(){
        if(isEmpty())return -1;
        return p[count];
    }






};
