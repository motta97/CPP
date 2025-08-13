#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool flag = true;
bool flag2 = true;
bool flag3 = true;
bool flag4 = true;
float sum = 0;
int num_of_p = 0;
int num_of_s = 0;
float childseries(vector<string>& v, int& i) {
    float seriessum = 0;
    if (v[i + 1] == "e") { cout << "Incorrect Input\n"; flag3 = false; }
    for (i++; i < v.size(); i++) {
        if (v[i] == "e") break;
        else if (!(isdigit(v[i][0]) || (v[i][0] == '-' && isdigit(v[i][1])))) {
            cout << "Wrong Description\n";
            flag = false;

            break;
        }
        else {
            seriessum += stof(v[i]);
            num_of_s += 1;
            flag4 = false;
        }
    }
    return seriessum;
}

float childparallel(vector<string>& v, int& i) {
    float parellelsum = 0;
    for (i++; i < v.size(); i++) {
        if (v[i] == "e") break;
        else if (!(isdigit(v[i][0]) || (v[i][0] == '-' && isdigit(v[i][1])))) {
            cout << "Wrong Description\n";
            flag = false;

            break;
        }
        else parellelsum += 1 / stof(v[i]);
    }
    return 1 / parellelsum;
}

void parentparallel(vector<string>& v, int size) {
    flag2 = false;
    if (v[1] == "e" || v[2] == "e") { cout << "Incorrect Input\n"; flag3 = false; }
    else {
        sum = 0; // Reset sum to 0
        for (int i = 1; i < size; i++) {
            if (v[i] == "S" || v[i] == "s") {
                sum += 1 / childseries(v, i);
                num_of_p += 1;

            }
            else if (v[i] == "e") break;
            else if (!(isdigit(v[i][0]) || (v[i][0] == '-' && isdigit(v[i][1])))) {
                cout << "Wrong Description\n";
                flag = false;

                break;
            }
            else {
                sum += 1 / stof(v[i]);
                num_of_p += 1;

            }
        }
        sum = 1 / sum; // Calculate 1 / sum
    }
}

void parentseries(vector<string>& v, int size) {
    if (v[1] == "e") cout << "Incorrect Input\n";
    else {
        sum = 0; // Reset sum to 0
        for (int i = 1; i < size; i++) {
            if (v[i] == "P" || v[i] == "p") sum += childparallel(v, i);
            else if (v[i] == "e") break;
            else if (!(isdigit(v[i][0]) || (v[i][0] == '-' && isdigit(v[i][1])))) {
                cout << "Wrong Description\n";
                flag = false;

                break;
            }
            else {
                sum += stof(v[i]);
                num_of_s += 1;
                flag4 = false;
            }
        }
    }
}

int main() {
    vector<string> v;
    string connection;
    getline(cin, connection);
    istringstream ss(connection);
    string word;
    while (ss >> word) {
        v.push_back(word);
    }

    if (v[0] == "P" || v[0] == "p") parentparallel(v, v.size());
    else if (v[0] == "S" || v[0] == "s") parentseries(v, v.size());
    else cout << "Wrong Description\n";

    if (sum != 0 && flag && (num_of_p > 1 || flag2) && (num_of_s >= 1 || flag4)) cout << "The total resistance = " << sum << endl;
    else if (num_of_p <= 1 && !flag2 && flag3 && !flag4)cout << "Incorrect Input\n";
    return 0;
}
