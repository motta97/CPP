#include <iostream>
using namespace std;
class stack_using_array{
    private:
    int size;
    int *p;
    int count = -1;
    public:
    stack_using_array(int s){
        this->size= s;
        p = new int[size];
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
    void pop(){
        if(!isEmpty()){
            count--;
        }
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




int main(){

    int size;
    cout<<"Enter the size of the stack: ";
    cin>>size;
    stack_using_array s1(size);
    cout<<s1.isEmpty()<<endl;
    s1.push(7);
    s1.push(8);
    cout<<s1.stackTop()<<endl;
    s1.pop();
    cout<<s1.stackTop()<<endl;
    s1.push(1);
    s1.push(10);
    s1.push(20);
    s1.peek(2);
    cout<<s1.stackTop()<<endl;

}
