int binary_search(vector <int> v,int target){
int high = v.size();
int low = 0;
int mid;

for(int i =0;i<ceil(log2(v.size()));i++){
mid = (high +low) /2;
if(v[mid]<target)low = mid +1;
else if( v[mid]>target)high = mid -1;
else return mid;

}
return -1;
//-1 means not found
}
