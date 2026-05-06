
#include<iostream>
#include <vector>
using namespace  std;
void add_to_vector(int index, vector<int>& v, int min) {
    v.push_back(0);
    for (int i = v.size() - 1; i >= index; i--) {
        v[i] = v[i - 1];
    }
    v[index] = min;
}
int seq(vector<int> seq, int x, int seqn) {
    int min;
    int diff;
    int min_index = 0;
    int res = 0;
    for (int i = 1; i <= x; i++) {
        min = INT_MIN;
        for (int j = 0; j < seqn - 2; j++) {
            diff = abs(seq[j] - i) - abs(seq[j + 1] - i);
            if (diff < min) {
                min = diff;
                min_index = j;
            }
            add_to_vector(j, seq, min);
        }

    }
    for (int i = 0; i < seqn - 1; i++) {
        res += abs(seq[i] - seq[i + 1]);
    }
    return res;



}



int main() {
    int x = 8;
    vector<int> y = { 7,2,10 };
    cout << seq(y, x,3) << endl;
}