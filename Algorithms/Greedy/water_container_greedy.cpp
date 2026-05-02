class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max=0;
        int area;
        int j = n-1;
        int i = 0;
        while(j!=i){
                area=computeArea(i,j,height[i],height[j]);
                if(area>max)
                    max=area;
                if(height[i]<height[j])i++;
                else j--;
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