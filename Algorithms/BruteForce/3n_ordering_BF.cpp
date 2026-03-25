#include<iostream>
using namespace  std;
void threeNOrder(int arr[], int n) {
    //one to work on negatives
    for (int i = 0; i < 3 * n - 1; i++) {
        if (arr[i] == -1) {
            for (int j = i; j > 0; j--) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
    //one to work on positives
    for (int i = 0; i < 3 * n - 1; i++) {
        if (arr[i] == 1) {
            for (int j = i; j < 3 * n - 1; j++) {
                swap(arr[j], arr[j + 1]);

            }
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