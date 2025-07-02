#include <iostream>
using namespace std;
int power(int n,int p){
        
    
  if(p==0)return 1;
  else if(p%2==0)return power(n*n,p/2);
  else return n*power(n*n,(p-1)/2);
}


int factorial(int x){

    if(x==0)//zero factorial is also one
    return 1;
    else
    return x*factorial(x-1);

}


float Taylor_Series(int n,int times){
    static int x=times;
    
    if(x>0){
        x--;
        return (power(n,times)/(float)factorial(times))+Taylor_Series(n,times-1);
        
        
    }
    else return 1;
    
    
    
    
}


int main()
{
   cout<<Taylor_Series(2,10)<<endl;
   
}
