void delete_from_max_heap(int A[],int n){
    //A is the array of the heap
    //n is the last index
    int x,i,j,tmp;
    x=A[n];//the last element
    A[1]=x;//the first element is the element to be removed
    i=1;
    j=2*i;

    while(j<n-1){

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
}
