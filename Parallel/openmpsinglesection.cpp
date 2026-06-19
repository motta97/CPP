#include<openmp.h>
#include<iostream>
using namespace std;

int main(){
    int x1,x2,y;
    //one single section executed by a single block
    //useful for code that isn't thread safe
    //there should be no branching within the block
#pragma omp single private(x1,x2) shared(y)
{
    //
}
}