#include<iostream>
using namespace  std;
int poly_evaluate(int a[], int x, int size) {
    int power;
    int result = 0;
    for (int i = 0; i < size; i++) {
        power = 1;
        //calculate power
        for (int j = 0; j < i; j++)
            power = power * x;

        result += power * a[i];
    }
    return result;
}
int main() {
    int arr[3] = { 1,2,3 };
    cout << poly_evaluate(arr, 2, 3) << endl;;
}