#include<iostream>
using namespace  std;
void selection_sort(int arr[], int size){
    //iteratively find the min, and swap it with the moving firs element.
    int tmp=0;
    int indxmin=0;
    for(int i =0;i<size-1;i++){
        indxmin=i;
        tmp=0;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[indxmin]){
                indxmin=j;
            }
        }
        tmp=arr[indxmin];
        arr[indxmin]=arr[i];
        arr[i]=tmp;
    }


}
int main(){
int arr[10]={10,9,8,7,5,6,4,3,2,1};
selection_sort(arr,10);
        for(int j=0;j<10;j++)
    {
        cout<<arr[j]<<" ";    
    }
}