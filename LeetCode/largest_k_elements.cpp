
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector <int> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	if (n >= k) {
		for (int i = v.size() - 1; i >= v.size() - k; i--) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = n-1; i >= 0; i--)cout << v[i] << " ";
		for (int i = 0; i < k - n; i++)cout << 0 << " ";
	}cout << endl;
}
