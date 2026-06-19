#include<openmp.h>
#include<iostream>
using namespace std;

int main(){
    int x1,x2,y;
    //each thread takes a signle section out of those
    //there should be no branching within the block
#pragma openmp sections shared(x1, x2) private(y)
{
    #pragma omp section
    {
        //
    }
    #pragma omp section
    {
        //
    }
    #pragma omp section
    {
        //
    }
}
}