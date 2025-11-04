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
class Solution {
public:
    bool isValid(string s) {
        
int len = s.length();
stack_using_array stack(len);
for(int i=0;i<len;i++){
if(s[i]=='(' || s[i]=='{' || s[i]=='['){
    //opening pracket
    stack.push(s[i]);
}
else if(s[i]==']'){
if(stack.stackTop()=='[')stack.pop();
else return false;
}
else if(s[i]=='}'){
    if(stack.stackTop()=='{')stack.pop();
    else return false;
}
else if(s[i]==')'){
    if(stack.stackTop()=='(')stack.pop();
    else return false;
}

}
if(stack.isEmpty())return true;
else return false;
    }
};
