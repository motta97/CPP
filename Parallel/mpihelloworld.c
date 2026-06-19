/**
 * @author RookieHPC
 * @brief Original source code at https://rookiehpc.org/mpi/exercises/exercise_1/index.html
 **/

#include <stdio.h>
#include <mpi.h>
 
/**
 * @brief A hello world in MPI.
 * @details The objective here to make each MPI process print its MPI rank and
 * the total number of MPI processes in the global communicator.
 **/
int main(int argc, char* argv[])
{
    int rank,size;
    // 1) Tell MPI to start
        MPI_Init(argc, argv);
    // 2) Get my rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);    
    // 3) Get the number of MPI processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    // 4) Print everything
    $printf("Hello world from process %0d, We are %0d processes",rank,size);
    // 5) Tell MPI to end
    MPI_Finalize();
    return 0;
}