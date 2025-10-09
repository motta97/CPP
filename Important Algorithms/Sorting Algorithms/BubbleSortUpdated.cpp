#include <iostream>
using namespace std;
void bubbleSort(int arr[],int size){
    int tmp=0;
    int number_of_swaps=0;
    for(int i =0;i<size;i++){
        number_of_swaps=0;
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
                number_of_swaps++;
            }

        }
        if(number_of_swaps==0)break;
    }
}

int main(){

    int arr[]={9,8,7,6,5,4,3,2,1};
    cout<<"Before sorting: "<<endl;
    for(int i =0;i<9;i++){
        cout<<arr[i]<<' ';
    }

    bubbleSort(arr,9);
    cout<<endl<<"After Sorting: "<<endl;
    for(int i =0;i<9;i++){
        cout<<arr[i]<<' ';
    }

}
