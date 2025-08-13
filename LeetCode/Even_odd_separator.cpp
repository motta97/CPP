
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
	int n;
	cin >> n;
	vector <int> v(n);
	vector <int> ev(0);
	vector <int> odd(0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] % 2 == 0) ev.push_back(v[i]);
		else odd.push_back(v[i]);
	}
	//printing the even values
	for (int i = 0; i < ev.size(); i++)cout << ev[i]<<" ";
	cout << endl;
	//printing the odd values
	for (int i = 0; i < odd.size(); i++)cout << odd[i]<<" ";
	cout << endl;
}
