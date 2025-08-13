// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
#include<vector>
using namespace std;
vector <string> reverse(vector<string> s1) {
    
    int n = s1.size();
    
    vector <string> s2(n);
    for (int i = 0; i < s1.size(); i++) {
        s2[i] += s1[--n];
    }
    
    return s2;
}
int main() {
    int t;
    string g;
    cin >> t;
    
    vector<string> s_reversed;
    while (t--) {
        cin >> g;
        vector <string> s(g.length());

        for (int i = 0; i < s.size(); i++)s[i] = g[i];
        s_reversed = reverse(s);
        if (s_reversed == s)cout << "Yes\n";
        else cout << "No\n";


    }

    return 0;
}
