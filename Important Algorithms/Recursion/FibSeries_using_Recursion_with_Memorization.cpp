int F[10];


int fib_with_memoriztion(int n){




if(n<=1){

    F[n]=n;
    return n;
}
else {

if(F[n-2]==-1){
F[n-2]=fib_with_memoriztion(n-2);

}
if(F[n-1]==-1){
F[n-1]=fib_with_memoriztion(n-1);

}
 F[n]=F[n-2]+F[n-1];   
return F[n-2]+F[n-1];


}






}
int main()
{
    for(int i=0;i<10;i++)F[i]=-1;
cout<<fib_with_memoriztion(6)<<endl;
  
   
}
