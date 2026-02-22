#include <iostream>
using namespace std;
int gcd_euclid(int m, int n) {

    if (m == 0)return n;
    if (n == 0)return m;
    return gcd_euclid(n, m % n);
}

