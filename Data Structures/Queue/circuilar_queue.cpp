#include<iostream>
class circuilar_queue{
    private:
    int size;
    int *static_array;
    int front;
    int rear;

    public:
    circuilar_queue(int s){
        this->size = s;
        static_array = new int[s];
        front = rear = 0;
    }
    bool isEmpty(){
        return front==0;
    }
    bool isFull(){
        if((front+1)%size==rear)return true;
        return false;
    }
    void enqueue(int d){
        if(isFull()){
            std::cout<<"Queue is Full\n";
            return;
        }
        rear=(rear+1)%size;
        static_array[rear]=d;
        
    }
    int dequeue(){
        int element;
        if(isEmpty()){
            std:: cout<<"Stack is empty\n";
            return -1;
        }
        element= static_array[front+1];
        front =(front+1)%size;
        return element;


    }
};
