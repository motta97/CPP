#include<iostream>
using namespace  std;
void threeNOrder(int arr[], int n) {
for(int i =0;i<3*n-2;i++){
    for(int j=0;j<3*n-2-i;j++){
        if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
    }
}

}



int main() {
    int arr[15] = { -1,0,0,1,-1,-1,-1,0,0,1,0,0,-1,1,0 };
    for (int i = 0; i < 15; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    threeNOrder(arr, 5);
    for (int i = 0; i < 15; i++) {
        cout << arr[i] << " ";
    }
}