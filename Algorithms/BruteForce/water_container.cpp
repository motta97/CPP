class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max=0;
        int area;
        for(int i =0 ;i<n;i++){
            for(int j= i+1;j<n;j++){
                area=computeArea(i,j,height[i],height[j]);
                if(area>max)
                    max=area;
            }
        }
        return max;
    }
    int computeArea(int i, int j, int h1, int h2){
        return ((j-i)*(min(h1,h2)));
    }
    int min(int h1, int h2){
        if(h1>h2)return h2;
        return h1;
    }

};