#include<vector>
using namespace std;
void insert(vector<int> A,int n){
    int tmp,i=n;
    tmp = A[n];
    while(i>1 &&tmp>A[i/2]  ){
        A[i]=A[i/2];
        i/=2;
    }
    A[i]=tmp;
}

void create_heap(vector<int> v){
    //assuming that the index 0 is not of interest as for typical heap use
  //the input is a normal vector that is not arranged as heap
  //we loop over all elements to form a heap
    int i;
    for(i=2;i<=v.size();i++){
        insert(v,i);
    }
}
