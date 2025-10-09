#include<iostream>
using namespace std;
bool repeatedItemChecker(int arr[], int size){

    for(int i =0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]) return true;
        }
    }
    return false;
    //this takes O(n^2)
}
bool repeatedItemCheckerSorted(int arr[],int size){
    //if we have a sorted array, repeated items are going to be near each other
    for(int i=0;i<size-1;i++){
        if(arr[i]==arr[i+1])return true;
    }
    return false;


}



int main(){


    int arr[]={6,7,8,6,5};
    cout<<repeatedItemChecker(arr,5) <<endl;

    //now, what if the array is sorted already?

    int arr2[]={10,20,30,40,40,50};
    cout<<repeatedItemChecker(arr2,6) <<endl;
}
