#include "mpi.h"
#include<iostream>
int main(int argc, char * argv[]){
    int n=50;//assume n is a constant for simplicity
    int x[n][n];
    int y[n][n];
    int z[n][n];
    int p[n][n];
    int t[n][n];
    int col=0;
    int num_rows[128]=0;
    int current_row=0;
    int start_row[128]=0;
    int my_rank;
    int size=0;
    double start_time;
    double end_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(size==128){
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        
        if(my_rank==0){
            start_time=MPI_Wtime();
            //initialize matrices
            for(int i =0;i<n;i++){
                for(int j=0;j<n;j++){
                    x[i][j]=i+1;
                    y[i][j]=j+1;
                    z[i][j]=i+j+2;
                }
            }
            //divide rows and send

            //process 0
            current_row=0;
            num_rows[0]=n/size;
            if(0<n%size){
                num_rows[0]++;
            }
            start_row[0]=current_row;
            current_row+=num_rows[0];

            //other processes
            for(int i = 1 ;i <128; i++){
                num_rows[i]=n/size;
                if(i < n %size){
                    num_rows[i]++;
                }
                start_row[i]=current_row;
                current_row+=num_rows[i];
                MPI_Send(&x,n*n, MPI_INT, i, 2, MPI_COMM_WORLD);
                MPI_Send(&y,n*n, MPI_INT, i, 3, MPI_COMM_WORLD);
                MPI_Send(&z,n*n, MPI_INT, i, 4, MPI_COMM_WORLD);
                MPI_Send(&num_rows[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
                MPI_Send(&start_row[i], 1, MPI_INT, i, 1, MPI_COMM_WORLD);
            }

            //process 0 calculation
            for(int i =start_row[my_rank]; i<(num_rows[my_rank]+start_row[my_rank]);i++){
                for(int col = 0; col<n; col++){
                    int result =0;
                    for(int k = 0; k<n; k++){
                        result+= x[i][k]*y[k][col];
                    }
                    t[i][col]=result;
                }
            }
            for(int i =start_row[my_rank]; i<(num_rows[my_rank]+start_row[my_rank]);i++){
                for(int col = 0; col<n; col++){
                    int result =0;
                    for(int k = 0; k<n; k++){
                        result+= t[i][k]*z[k][col];
                    }
                    p[i][col]=result;
                }
            }
            //now the process 0 should recieve the result from workers
            
            for(int i = 0; i < size; i++){
                int local_result[num_rows[i]][n];
                MPI_Recv(&local_result, num_rows[i]*n, MPI_INT, i, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                for(int j=0; j < num_rows[i];j++ ){
                    for(int k=0;k<n;k++){
                        p[j+start_row[i]][k]=local_result[j][k];
                    }
                }
            }

            end_time=MPI_Wtime();
            printf("SUCCESS! total time taken is: ...%f",end_time-start_time);
            MPI_Finalize();

        }
        else{
            //workers processes
            //we also need to take x, y, and z
            MPI_Recv(&x, n*n, MPI_INT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(&y, n*n, MPI_INT, 0, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(&z, n*n, MPI_INT, 0, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(&num_rows[my_rank], 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(&start_row[my_rank], 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            int local_result[num_rows[my_rank]][n];
            for(int i =start_row[my_rank]; i<(num_rows[my_rank]+start_row[my_rank]);i++){
                for(int col = 0; col<n; col++){
                    int result =0;
                    for(int k = 0; k<n; k++){
                        result+= x[i][k]*y[k][col];
                    }
                    t[i][col]=result;
                }
            }
            for(int i =start_row[my_rank]; i<(num_rows[my_rank]+start_row[my_rank]);i++){
                for(int col = 0; col<n; col++){
                    int result =0;
                    for(int k = 0; k<n; k++){
                        result+= t[i][k]*z[k][col];
                    }
                    local_result[i-start_row[my_rank]][col]=result;
                }
            }
            MPI_Send(&local_result, num_rows[my_rank]*n, MPI_INT, 0, 5, MPI_COMM_WORLD);
            MPI_Finalize();   
        }

    }
    else{
        printf("Sorry must be 128 processes/n");
        MPI_Abort(MPI_COMM_WORLD, -1);
    }

    return 0;

}