#include <iostream>
using namespace std;
int fun(int n,int p){
        
    
   if(p>0)
       
       return fun(n,p-1)*n;
   
   else return 1;
}
int main()
{
   cout<<fun(3,4)<<endl;
}
