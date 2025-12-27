void insert(int A[],int n){
    int tmp,i=n;
    tmp = A[n];
    while(i>1 &&tmp>A[i/2]  ){
        A[i]=A[i/2];
        i/=2;
    }
    A[i]=tmp;
}
