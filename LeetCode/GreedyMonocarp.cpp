
#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

bool comp(int a, int b) {
    return a >= b;
}
vector<int> findLinearSums(const vector<int>& arr) {
    // Check if the array is empty
    if (arr.empty()) {
        return {}; // Return an empty vector for an empty input
    }

    vector<int> results;
    int currentSum = arr[0]; // Initialize with the first element

    // Iterate through the array starting from the second element
    for (size_t i = 1; i < arr.size(); ++i) {
        currentSum += arr[i]; // Add the current element to the cumulative sum
        results.push_back(currentSum); // Store the cumulative sum
    }

    return results; // Return the result vector
}

int main()
{
    //now we have the possible sums
    int t;
    cin>>t;
    while(t--){
        int n,k,m;
        cin>>n>>k;
        vector <int> v;
        vector <int> results;
        vector <int> final;
        for(int i=0;i<n;i++){
            cin>>m;
            v.push_back(m);
            
        }
        sort(v.begin(),v.end(),comp);
        //now we got the array, we want to find possible susm
         results =findLinearSums(v);
        for(int i=0;i<n;i++){
            results.push_back(v[i]);
        }
        
        //we want to exclude the elemnts greater than push_back
        //we also want to subtract each element from than k
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<results.size();i++){
            if(k-results[i]>=0){
                final.push_back(k-results[i]);
            }
            
            
        }
        //we did that, now we want to find the min number in this array
        
        sort(final.begin(),final.end());
        cout<<final[0]<<endl;
        
        
        
        
        
    }

    return 0;
}
