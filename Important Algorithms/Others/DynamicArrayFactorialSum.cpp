#include <iostream>
using namespace std;
float factorial(int n){
    if(n==0)return 1;
    return n*factorial(n-1);
}
float sumArray(float arr[],int size){
    float sum=0;
    for(int i =0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}
float factorialSum(float *p, int size){

    for(int i =0;i<size;i++){
        p[i]=1/(factorial(i));
    }
    return sumArray(p,size);
}

int main(){
int n;
cout<<"Enter the number of elements: ";
cin>>n;
float *p = new float[n];
cout<<"Total Is: "<<factorialSum(p,n)<<endl;

}