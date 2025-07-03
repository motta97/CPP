void fib (int arr[],int x)
{
   static int i = x;
   static int j = 1;
    arr[0]=0;
    arr[1]=1;
    if(j==i) return;
    else {
        j++;
        arr[j]=arr[j-2]+arr[j-1];
        fib(arr,x);

    }



}

int main()
{

   int arr[10];
   fib(arr, 10);
    for(int i=0;i<10;i++)
    {
         cout<<arr[i]<<" ";
    }
   
}
