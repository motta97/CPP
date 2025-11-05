class queue{
    private:
    int size;
    int *static_array;
    int front;
    int rear;
    public:
    queue(int size){
        front= rear=-1;
        this->size=size;
        static_array=new int[this->size];
    }
    bool isFull(){
        return rear==size-1;
    }
    bool isEmpty(){
        return front==-1;
    }
    void enqueue(int d){
        if(isFull())return;
        if(front==-1)front =0;
        rear++;
        static_array[rear]=d;
    }
    int dequeue(){
        int element;
        if(isEmpty()){
            cout<<"Queue is Empty!\n";
            return -1;
        }
        element = static_array[front];
        if(front >= rear){
            front = rear = -1;
        }
        else front++;
        return element;
    }



};
