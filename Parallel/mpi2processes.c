/**
 * @author RookieHPC
 * @brief Original source code at https://rookiehpc.org/mpi/exercises/exercise_2/index.html
 **/

#include <stdio.h>
#include <mpi.h>

/**
 * @brief Exercise about sending a message in MPI.
 * @details This exercisse just consits of 2 MPI processes, the first one sends
 * a message and the second one receives it. The message to sendis just an
 * integer with the value 12345. The receiver must print the value received.
 **/
int main(int argc, char* argv[])
{
    int my_rank;
    int buffer;
	// 1) Tell MPI to start
    MPI_Init(argc,argv);

	// 2) Check that the application is run with 2 MPI processes
	int comm_size;
	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
	if(comm_size != 2)
	{
		printf("This application must be run with 2 MPI processes, not %d.\n", comm_size);
		MPI_Abort(MPI_COMM_WORLD, -1);
	}

	// 3) Get my rank
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    if(my_rank==0){
        buffer=512004;
        printf("I am the sender, and I am sending: %0d",buffer);
        MPI_Send(&buffer, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    else{
        MPI_Recv(&buffer, 1, MPI_INT, 0,0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    }
    MPI_Finalize();
	// 4) If my rank is 0, I am the sender
		// 4.1) Print the value to send
		// 4.2) Send the value
	
	// 5) If my rank is 1, I am the receiver
		// 5.1) Receive the value
		// 5.2) Print the value received

	// 6) Tell MPI to stop

	return 0;
}