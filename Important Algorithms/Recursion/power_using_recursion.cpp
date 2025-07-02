#include <iostream>
using namespace std;
int fun(int n,int p){
        
    
   if(p==0)return 1;
  else if(p%2==0)return fun(n*n,p/2);
  else return n*fun(n*n,(p-1)/2);
}
int main()
{
   cout<<fun(3,4)<<endl;
}
