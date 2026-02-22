#include <iostream>
using namespace std;
int gcd_iterative(int m, int n) {
    int x;
    if (m < 0 || n < 0)return -1;
    x = min(m, n);
    while (x != 0) {
        if (m % x == 0 && n % x == 0)return x;
        else x--;
    }
    return x;
}