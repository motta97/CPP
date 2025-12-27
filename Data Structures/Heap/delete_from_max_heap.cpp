void delete_from_max_heap(int A[],int &n){
    //A is the array of the heap
    //n is the last index
    int x,i,j,tmp;
    x=A[1];
    A[1]=A[n];//the first element is the element to be removed
    i=1;
    j=2*i;
    n--;
    while(j<=n){

        if(A[j+1]>A[j]){
            j+=1;
        }
        if(A[i]<A[j]){
            //swap
            tmp =A[i];
            A[i]=A[j];
            A[j]=tmp;

            i=j;
            j=2*i;
        }
        else break;
    }
    A[n+1]=x;//for sorting the array using heap sort
}
