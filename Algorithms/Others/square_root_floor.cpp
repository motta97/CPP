#include<iostream>
using namespace std;
int sqrt_floor(int n){
    if(n<2)return n;
    long x=1;
    while(x*x<=n){
    x++;
}
    return x-1;
}
