#include<openmp.h>
#include<iostream>
using namespace std;

int main(){
    omp_set_num_threads(5);
    int a[10],b[10],c[10];
    int i;
    int N=10
    //each thread takes a protion of the unrolled for
    //there should be no branching within the block
    #pragma omp parallel shared(i) private (a,b,c)
    {
        #pragma omp for schedule(static, 2) nowait
        for(i=0;i<N;i++){
            c[i]=a[i]+b[i];
        } 
      
    }
}