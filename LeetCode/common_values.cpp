#include <iostream> 
#include <string> 
#include<vector>
#include<cmath>
using namespace std; 
vector <int>  common_values (vector <int> v1, vector <int> v2){
    vector <int> v;
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++)
        {
            if(v1[i]==v2[j]){v.push_back(v1[i]);
                break;
                
                
            }}
    }
    return v;

}
int main(){
    vector <int> v1,v2,com_values;
    cout<<"Enter the elements of the first array, 0 when you're finsihed:\n";
    int n;
    while(true){
      cin>>n;
      if(n==0)break;
      v1.push_back(n);
    }
    cout<<"Enter the elements of the second array, 0 when you're finsihed:\n";
     while(true){
      cin>>n;
      if(n==0)break;
      v2.push_back(n);
    }
    com_values=common_values(v1,v2);
    cout<<"The common values between the two arrays are: ";
    for(int i=0; i<com_values.size();i++)
    cout<<com_values[i]<<" ";
    cout<<endl;
    
}
