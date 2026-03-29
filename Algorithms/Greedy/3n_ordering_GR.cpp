#include<iostream>
using namespace  std;
void threeNOrder(int arr[], int n) {
    //one to work on negatives
    for (int i = 0; i < 3 * n - 1; i++) {
            for (int j = i; j > 0; j--) {
                if(arr[j]==-1 && j!=0 &&arr[j-1]!=-1)swap(arr[j], arr[j - 1]);
                else break;
            }
        }
    for (int i = 0; i < 3 * n - 1; i++) {
            for (int j = i; j < 3 * n - 1; j++) {
                if(arr[j]==1 && j!=3*n-1 &&arr[j+1]!=1)
                swap(arr[j], arr[j + 1]);
                else break;

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