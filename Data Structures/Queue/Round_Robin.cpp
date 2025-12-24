#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //take inputs
    int n,q;
    cin>>n>>q;
    char x;
    int y;
    queue<char> myCharQueue;
    queue<int> myIntQueue;
    
    for(int i =0;i< n;i++){
        cin>>x;
        cin>>y;
        myCharQueue.push(x);
        myIntQueue.push(y);
    }
    char a;
    int b;
    int left_time;
    while(!myCharQueue.empty()){
       
        a=myCharQueue.front();
        b=myIntQueue.front();
        myCharQueue.pop();
        myIntQueue.pop();
        cout<<a;
        left_time=b-q;

        if(left_time>0){
            myCharQueue.push(a);
            myIntQueue.push(left_time);
        }

    }
    
    return 0;
}
