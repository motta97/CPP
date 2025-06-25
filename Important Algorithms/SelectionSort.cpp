int main(){
int arr_unsorted[10]={10,9,8,7,6,5,4,3,2,1};
int min = arr_unsorted[0];
int temp=0;
int index=0;
for(int i=0;i<10;i++){
    min = arr_unsorted[i];
    for(int j=i;j<10;j++){
        if(arr_unsorted[j]<=min){min = arr_unsorted[j]; index =j;}
    }
    temp = arr_unsorted[i];
    arr_unsorted[i]=arr_unsorted[index];
    arr_unsorted[index]=temp;

}
for(int i=0;i<10;i++){
    cout<<arr_unsorted[i]<<" ";

}
}
