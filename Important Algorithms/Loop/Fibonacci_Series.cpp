void fib (int arr[],int x)
{
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<x;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }



}

int main()
{

   int arr[10];
   fib(arr, 10);
    for(int i=0;i<100;i++)
    {
         cout<<arr[i]<<" ";
    }
   
}
