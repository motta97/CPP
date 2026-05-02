#include<iostream>
#include <vector>
using namespace  std;
int maxCrossSum(int l, int r, int m, vector<int>& arr) {

    int max_sum = INT_MIN;
    int max_sum2 = INT_MIN;
    int sum = 0;
    //find the max in the left
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > max_sum)max_sum = sum;
    }
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > max_sum2)max_sum2 = sum;
    }
    return max_sum + max_sum2;
}
int maxSum(int l, int r, vector<int>& arr) {
    if (l > r)return -1;
    if (l == r)return arr[l];
    int m = l + (r - l) / 2;
    int left_sum = maxSum(l, m, arr);
    int right_sum = maxSum(m + 1, r, arr);
    int cross_sum = maxCrossSum(l, r, m, arr);

    if (left_sum > right_sum) {
        if (left_sum > cross_sum)return left_sum;
        else return cross_sum;
    }
    else {
        if (right_sum > cross_sum)return right_sum;
        else return cross_sum;
    }
}


int main() {
    vector<int>arr = { -5,5,4,-3,1 };
    cout << maxSum(0, 4, arr) << endl;
}