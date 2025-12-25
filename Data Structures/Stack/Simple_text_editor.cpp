#include <cmath>
#include<string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<string> st;
    string s ="";
    string tmp;
    int operaton;
    int delete_el;
    int print_k;
    int q;
    cin>>q;
    while(q--){
        cin>>operaton;
        if(operaton==1){
            st.push(s);
            cin>>tmp;
            s+=tmp;
        }
        else if(operaton==2){
            st.push(s);
            cin>>delete_el;
            if (delete_el <= s.length()) {
                s.resize(s.length() - delete_el);
                
             }
        }
        else if(operaton==3){
            cin>>print_k;
            if(print_k<=s.length()){
                cout<<s[print_k-1]<<endl;
            }
        }
        else if(operaton==4){
            s=st.top();
            st.pop();
        }
    }
    return 0;
}
