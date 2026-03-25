#include<iostream>
using namespace  std;
void alternating(int arr[],int n){
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
}


int main() {
    int arr[8] = {0,1,0,1,0,1,0,1};
    for (int i = 0; i < 15; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    alternating(arr,8);
    for (int i = 0; i < 15; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}