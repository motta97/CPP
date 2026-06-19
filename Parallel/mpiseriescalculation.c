#include<iostream>
#include<mpi.h>
int main(int argc, char * argv[]){
    int size;
    int local_n;
    int k;
    int x;
    double result=0;
    int recieved=0;
    int my_rank;
    double start_time;
    int start=local_n;
    int remaining_end=(local_n*size)+k%8;
    MPI_Init(&argc, &argv);
    start_time = MPI_Wtime();
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    

    if(size!=8){
        printf(
            "Sorry, size has to be of 8 processes"
        );
        MPI_Abort(MPI_COMM_WORLD, -1);
    }
    else{
        if(my_rank==0){
            scanf("%0d",&k);
            scanf("%0d",&x);
            local_n=(k+1)/size;
            //what process 0 calculates is its share out
            //of the 8 processes + what's remainig untaken
            for(int i =0;i<start;i++){
                result+=(pow(-1,i+1)*pow(x,5*i)/(fact(2*i)));
            }
            //remaining
            for(int i = locl_n*size+1; i<=remaining_end; i++){
                result+=(pow(-1,i+1)*pow(x,5*i)/(fact(2*i)));
            }
            //other processes
            for(int i =1;i<8;i++){
                MPI_Send(&k, 1, MPI_INT, i, 2, MPI_COMM_WORLD);
                MPI_Send(&start,1,MPI_INT,i,0,MPI_COMM_WORLD);
                MPI_Send(&x, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
                start+=local_n;
            }
            for(int i=1; i<8; i++){
                MPI_Recv(&recieved, 1, MPI_INT, i, 0, MPI_COMM_WORLD,
                MPI_STATUS_IGNORE
                );
                result+=recieved;
            }

        }
        else{
            MPI_Comm_size(MPI_COMM_WORLD, &size);
            MPI_Recv(&k, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            local_n=(k+1)/size;
            MPI_Recv(&start, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(&x, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            for(int i=start;i<start+local_n;i++){
                recieved+=(pow(-1,i+1)*pow(x,5*i)/(fact(2*i)));
            }
            MPI_Send(&recieved, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
        if(my_rank==0){
            printf("The final result is: %0d",result);
            printf("Total time is: %0d",MPI_Wtime()-start_time);
            MPI_Finalize();
        }
    }
}