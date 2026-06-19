#include<openmp.h>
#include<iostream>
using namespace std;

int main(){
    omp_set_num_threads(5);
    int x1, x2;
    //all threads execute the same thing
    //there should be no branching within the block
    #pragma parallel shared(x1) private (x2)
    {
        cout<<"Im thread: %0d",omp_get_thread_num()<<endl;
    }
}