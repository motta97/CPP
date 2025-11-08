#include<iostream>
using namespace std;
#include <vector>
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




bool AreEqual(string a, string b){
    stack_using_array<char> s1(a.length()),s2(b.length());
    for(int i =0;i<a.length();i++){
        s1.push(a[i]);
    }
    for(int j =0;j<b.length();j++){

        s2.push(b[j]);
    }
    int i =0,j=0;
    char tmp;
    vector<char> x ;
    vector<char> y;
   
    while(!s1.isEmpty()){
        tmp =s1.pop();
        if(tmp=='#'){
            s1.pop();
        }
        else{
            x.push_back(tmp);
            i++;
        }

    }
        while(!s2.isEmpty()){
        tmp =s2.pop();
        if(tmp=='#'){
            s2.pop();
        }
        else{
            y.push_back(tmp);
            j++;
        }
        
    }
    if(i!=j)return false;
    for(int m=0;m<i;m++){
        if(x[i]!=y[i])return false;
    }
    return true;







}
int main(){

 string x = "abc#";
 string y = "abc#d#e#f";
 cout<<AreEqual(x,y)<<endl;
}
