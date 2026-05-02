#include<iostream>
using namespace  std;
void quick_sort(int arr[],int left_index,int right_index){
    if(left_index>=right_index)return;
    int j=left_index,i=left_index-1;
    for(j;j<=right_index;j++){
        if(arr[right_index]>=arr[j]){//arr[right_index]is the pivot
            i++;
            swap(arr[i],arr[j]);
        }
        
    }
    
    quick_sort(arr,0,i-1);
    quick_sort(arr,i+1,right_index);
}
int main() {
int arr[]={10,9,8,7,6,8,4,24,489,12,90};
quick_sort(arr,0,10);//note that we pass size-1
for(int i =0;i<11;i++){
    cout<<arr[i]<<" ";
}
}