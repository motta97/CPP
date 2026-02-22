#include <iostream>
using namespace std;
int fun(int n){
    
    
    if(n==1){
        return 1;
    }
    else return fun(n-1)+n;
}
int main()
{
  int x=5;//this can be changed to whatever, but it has to be greater than zero
   cout<<fun(x)<<endl;
}
