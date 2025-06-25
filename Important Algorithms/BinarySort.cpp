void bubble_sort(int v[],int size){

int swap_counter =-1;
int temp;

for(int i =0;i<size;i++){
    swap_counter=0;
    for(int j=0;j<size-1;j++){
        if(v[j]>v[j+1]){
            temp=v[j];
            v[j]=v[j+1];
            v[j+1]=temp;
           swap_counter++;
        }
    }
    if(!swap_counter) return ;
}

}
