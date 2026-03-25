#include<iostream>
using namespace  std;
void change_making(int set_of_coins[],int n,int m, int result[]){
    for(int i=0;i<m;i++){
        if(n<set_of_coins[i]){
            result[i]++;
            n-=set_of_coins[i];
            i--;
        }
    }
}
int main() {
//assume we have 25, 10, 5, 1
// where m = 4 and n the change = 48
int result[4]={0,0,0,0};
int set_of_coins[4]={25,10,5,1};
change_making(set_of_coins,48,4,result);
for(int j=0;j<4;j++){
    cout<<result[j]<<" ";
}
cout<<endl;
}