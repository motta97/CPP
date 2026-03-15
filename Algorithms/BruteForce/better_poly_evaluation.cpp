#include<iostream>
using namespace  std;
int poly_evaluate(int a[], int x, int size) {
    int power=1;
    long long result = a[0];
    for (int i = 1; i < size; i++) {
        power*=x;
        result += power * a[i];
    }
    return result;
}
int main() {
    int arr[3] = { 1,2,3 };
    cout << poly_evaluate(arr, 2, 3) << endl;;
}