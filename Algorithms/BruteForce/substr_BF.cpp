//count the number of substrings in a text that starts with
//an s and ends with s
#include<iostream>
using namespace  std;
int substr_s(string s) {
int n = s.size();
int counter=0;
for(int i =0;i<n;i++){
    if(s[i]=='s'||s[i]=='S'){
        for(int j=i+1;j<n;j++){
            if(s[j]=='s'||s[j]=='S')counter++;
        }
    }
}
return counter;

}



int main() {
cout<<substr_s("AIN_SHAMS_UNIVERSITY")<<endl;
}