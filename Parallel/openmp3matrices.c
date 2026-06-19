#include<omp.h>

int main(int argc, char * argv[]){

    int n=50; //suppose n is constant for simplicity
    int x[n][n];
    int y[n][n];
    int z[n][n];
    int t[n][n];
    int p[n][n];
    int num_threads = 32*4;//32 cores with 4 threads per core
    omp_set_num_threads(num_threads);
    //initializing matrices with arbitraray values
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            x[i][j]=i+1;
            y[i][j]=j+1;
            z[i][j]=i+j+2;
        }
    }



    #pragma omp parallel shared(x,y,z,t,p)
    {
        #pragma omp for schedule(static)
        {
            for( int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n; j++){
                    int sum = 0;
                    for(int k=0; k< n; k++){
                        sum += x[i][k]*y[k][j];
                    }
                    t[i][j]=sum;
                }
            }

        }
    }
    #pragma omp parallel shared(x,y,z,t,p)
    {
        #pragma omp for schedule(static)
        {
            for( int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n; j++){
                    int sum = 0;
                    for(int k=0; k< n; k++){
                        sum += t[j][k]*z[k][j];
                    }
                    p[i][j]=sum;
                }
            }

        }
    }
    printf("SUCCESS!");




}