#include <iostream> 
#include <string> 
#include<vector>
#include<cmath>
using namespace std; 
/*
now I don't have a problem with finiding the min value but I mean I don't know how to find the pair associated with this min!! but I have to find it myself without the help of the AI
*/
int min(vector <int>v ){
    int min_num=v[0];
    for(int i=1;i<v.size();i++){
        
     if(v[i]<min_num)min_num=v[i];
        
    }
    
    return min_num;
}
vector<int> pair_checker(vector <int> v,int x){
    int min_num;
    vector <int> v3;
    vector<int> v4(2);
    for(int i=0;i<v.size();i++){
       for(int j=i+1;j<v.size();j++){
            v3.push_back(abs(x-(v[i]+v[j])));
            
       }
    }
    // for(int i=0;i<v3.size();i++){
    //     cout<<v3[i]<<" ";
    //     cout<<endl;
    // }
    min_num=min(v3);
    
     for(int i=0;i<v.size();i++){
       for(int j=i+1;j<v.size();j++){
           if(min_num==x-(v[i]+v[j])){
               v4[0]=v[i];
               v4[1]=v[j];
           }
            
       }
    }
    return v4;
}


int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    vector <int> v;
    cout<<"Enter the elements of the array: ";
    int n;
    for(int i=0;i<size;i++){
        cin>>n;
        v.push_back(n);
    }
    cout<<"Enter the X: ";
    int x;
    cin>>x;
    vector <int>v4=pair_checker(v,x);
    
    for(int i=0;i<2;i++){
        cout<<v4[i]<<" ";
    }
    cout<<endl;
    
    
    
}
