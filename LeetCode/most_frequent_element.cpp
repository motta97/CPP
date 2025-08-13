
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int main() {
	int n;
	cin >> n;
	int most_f = 0;
	int num_of_fr = 1;
	int max_num_of_fr = 1;
	vector <int> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];

	}
	sort(v.begin(), v.end());
	most_f = v[0];
	if (v.size() > 1) {
		for (int i = 0; i < n; i++) {


			if (i < n - 1 && v[i] == v[i + 1]  ) {
				num_of_fr += 1;
				
			}
			if (num_of_fr >= max_num_of_fr) {
				most_f = v[i];
				max_num_of_fr = num_of_fr;

			}
			if( i < n - 1 && v[i]!=v[i+1] )num_of_fr = 0;


		}
		cout << most_f << endl;
	}
	else cout << most_f << endl;
}
