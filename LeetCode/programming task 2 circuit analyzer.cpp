
#include <iostream>
#include<string>
#include<vector>
using namespace std;
float sum = 0;
void series(float r) {
	if (r != 0)sum += r;
}
void parallel(float r) {
	
	if (r != 0)sum += 1 / r;
}
int main() {
	vector <string> v(5);
	for (int i = 0; i < 5; i++)v[i] = "0";

	for (int i = 0; i < 5; i++) {
		cin >> v[i];
		if (v[i] == "e")break;
	}
	if (v[1] == "e")cout << "Incorrect Input\n";
	else {
		if (v[0] == "s" || v[0] == "S") {
			for (int i = 1; i < 5; i++) {
				if (v[i] != "e")	series(stof(v[i]));
			}
		}
		else if (v[0] == "p" || v[0] == "P") {
			if (v[2] == "e")cout << "Incorrect Input\n";
			else {
				for (int i = 1; i < 5; i++) {
					if (v[i] != "e") {

						parallel(stof(v[i]));
					}
				}sum = 1 / sum;
			}

		}//call parallel function
		else cout << "Incorrect Input\n";

		if (sum != 0)cout << "The total resistance = " << sum << endl;



	}
}
