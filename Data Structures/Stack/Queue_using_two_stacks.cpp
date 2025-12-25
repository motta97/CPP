#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<int> s_orig;
    stack<int> s_reversed;
    int q;
    cin>>q;
    int operation;
    int newElement;
    int tmp;
    while(q--){
        cin>>operation;
        if(operation==1){
            cin>>newElement;
            //enqueue
            s_orig.push(newElement);
        }

        
        else if(operation==2){
            //dequeue
            //move elements to reversed
            while(!s_orig.empty()){
                tmp=s_orig.top();
                s_orig.pop();
                s_reversed.push(tmp);
            }
            //remove the last element
            s_reversed.pop();
            //move it back to original
            while(!s_reversed.empty()){
                tmp=s_reversed.top();
                s_reversed.pop();
                s_orig.push(tmp);
            }
        }
        else if(operation==3){
            //print
            while(!s_orig.empty()){
                tmp=s_orig.top();
                s_orig.pop();
                s_reversed.push(tmp);
            }
            //print the last element
            cout<<s_reversed.top()<<endl;
            //move it back to original
            while(!s_reversed.empty()){
                tmp=s_reversed.top();
                s_reversed.pop();
                s_orig.push(tmp);
            }
        }






    }
    return 0;
}
