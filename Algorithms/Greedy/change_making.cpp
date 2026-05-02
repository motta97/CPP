#include<iostream>
using namespace  std;
void change_making(int set_of_coins[], int amount, int m, int result[]) {
    for (int i = 0; i < m; i++) {
        if (amount / set_of_coins[i] != 0) {
            result[i] = amount / set_of_coins[i];
            amount = amount % set_of_coins[i];
        }
        if (amount == 0)break;
    }
}
int main() {
    //assume we have 25, 10, 5, 1
    // where m = 4 and n the change = 48
    int result[4] = { 0,0,0,0 };
    int set_of_coins[4] = { 25,10,5,1 };
    change_making(set_of_coins, 48, 4, result);
    for (int j = 0; j < 4; j++) {
        cout << result[j] << " ";
    }
    cout << endl;
    //another example that let the greedy fails
    int set_of_coins2[3] = { 25,10,1 };
    int n = 30;
    int result2[3] = { 0,0,0 };
    //the alogrithm would choose one of the 25 and 5 of the 1, total 6 coins
    //but 3 of 10 is 6 coins only
    change_making(set_of_coins2, n, 3, result2);
    for (int j = 0; j < 3; j++) {
        cout << result[j] << " ";
    }
    cout << endl;
}