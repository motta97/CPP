#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int m = 0;
int min2;
int maxArr(int sum) {

    if (!m) {
        min2 = sum;
        m = 1;
    }
    if (sum >= min2) {
        min2 = sum;
        return sum;



    }
}
int main() {
    int sum = 0;
    int t = 0;
    int n;
    cin >> t;
    while (t--) {
        cout << "Enter the size of the array!" << endl;
        cin >> n;
        vector <int> v(n);
        int mmax;
        sum = 0;
        for (int i = 0; i < n; i++)cin >> v[i] ;

        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += v[j];
                //cout<<mmax<<endl;
                mmax = maxArr(sum);
            }
            
            
        }
        cout << mmax << endl;
        m = 0;

    }



}
