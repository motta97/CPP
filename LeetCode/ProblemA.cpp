#include <iostream>
#include <vector>
#include <set>
#include <map>
#include<algorithm>
using namespace std;

int main()
{
    int t,s;
    int score;
    cin>>t;
    while(t--){
        score=0;
        cin>>s;
    bool flag=true;
    vector <int> v(s);
    vector <int> v2(0);
    vector <int> v3(0);

    for(int i=0;i<v.size();i++)
        cin>>v[i];

    //now we read the elements of the array, now it's time to do the operaion
    for(int i=0;i<v.size();i++)
    {

        for(int j=i+1;j<v.size();j++){
flag =true;
            for(int x=0;x<v2.size();x++){
                if(j==v2[x])
                {
                    flag= false;
                    break;

                }
            }
            for(int x=0;x<v2.size();x++){
                if(i==v2[x])
                {
                    flag= false;
                    break;

                }
            }


            if(v[i]==v[j]&&flag){
                //if it was equal we basically want to do two things
                // first one is to increase the score by one
                // second one is to account for these indices S.T they are not compared in the coming rounds
                score++;
                v2.push_back(j);
                v2.push_back(i);
                break;

            }


        }

    }
    cout<<score<<endl;



}

}
