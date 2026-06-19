#include<MPI.h>
#include<iostream>
using namespace std;
int main(){
// Write a C program that uses MPI parallelization to compute matrix P. 
// This computation requires the multiplication of three n×n matrices X, Y, and Z to compute another 
// matrix P = X × Y × Z
// Your program 
// should use 128 processes and should also compute the overall time to 
// compute matrix P. 
// in MPI we have 6 main functions init, finalize, send, recv, comm_rank, comm_size
//
//QUESTION 1: WHERE TIME MEASUREMENT IS TAKEN?
//QUESTION 2: HOW CAN YOU DETERMINE THE NUMBER OF COMMUNICATING PROCESSES

int rank, int size;
int start_time;
int end_time;
int n=5000;
int row_start;
int num_rows;
int row_iterator;
int col_iterator;
int intermediary_mtx[n][n];
int p[n][n],x[n][n],y[n][n],z[n][n];
int local_num_iterations = (n*n)/128;
MPI_Status status;
// how can we distribute that over communicating processes?
// we want set of processes to calculte x*y and others multiply the result by z
// or as a better approach, each process calculates set of cells of p
// or even better, each process takes a set of rows (it can be unevely distributed)
// and the first process to display the result
// this's done by send and recieve
MPI_Init();
num_rows=n/128;//integer division
if(num_rows==0)num_rows=1;
start_time=MPI_Wtime();
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int local_num_iterations = (n*n)/128;
if(rank!=0){
        //computing a single cell
        //the row_col_iterator go from 0 all the way up to n
        //where all processes share the matrices and all variables exept for rank
        //each process should receive the row_col_iterator value;
        //note that each process won't calculate a single cell only, it would calculate n*n/128 cells
        //since we have only 128 processes
        
        MPI_Recv(&row_start, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        row_iterator=row_start;
        col_iterator=0;
        for(int j=0;j<num_rows*n;j++){
            if(row_iterator<n && col_iterator <n){
                for(int i=0;i<n;i++){
                    intermediary_mtx[row_iterator][col_iterator]+=x[row_iterator][i]*y[i][col_iterator];
                }
                for(int i=0;i<n;i++){
                    p[row_iterator][col_iterator]+=intermediary_mtx[row_iterator][i]*z[i][col_iterator];
                }
                if(col_iterator==(n-1)){
                    col_iterator=0;
                    row_iterator++;
                }
                else{
                    col_iterator++;
                }
            }
        }
}
else {
    //my rank = 0
    row_start=0;
    //assuming that matrices x,y, and z are initialized
    for(int i =1;i<128;i++){
        MPI_Send(row_start, 1, MPI_INT, i, 1, MPI_COMM_WORLD );

        row_start+=num_rows;
    }
    end_time=MPI_Wtime();
    printf("Success with total time: %0d",end_time-start_time);

}
MPI_Finalize();

}