#include <iostream> 
#include <string> 
#include<vector>
#include<cmath>
using namespace std; 
int factorial (int n){
    int sum=1;
    for(int i=1;i<=n;i++){
        sum*=i;
    }
    return sum;
}
int main(){
    int num;
    cout<<"Enter a number and I will till you if it's a strong or not: ";
    cin>>num;
    string s=to_string(num);
    int sum=0;
    for(int i=0;i<s.length();i++){
        sum+=factorial(s[i]-'0');
    }
    if(sum==num)cout<<"Strong Number!\n";
    else cout<<"Not a Strong Number\n";
}
