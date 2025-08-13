
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	int count2 = 0;
	while (t--) {
		int sum = 0;
		int n;
		count2 = 0;
		cin >> n;

		vector <int> len(n);
		
		for (int i = 0; i < n; i++)cin >> len[i];
		sort(len.begin(), len.end());
		for (int i = 1; i <= len[n-1]; i++) {
			 
				count2 = count(len.begin(), len.end(), i);
				if (count2 % 4 < count2 % 3)sum += count2 / 4;
				else if (count2%4==count2%3) {
					sum += count2 / 3;
				}
				else sum += count2 / 3;
			

		}


		cout << sum << endl;




	}





}
