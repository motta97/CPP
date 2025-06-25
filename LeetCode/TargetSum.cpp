 vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ret;
        for(int i =0;i<nums.size();i++){
            for(int j= i+1;j<nums.size();j++){
                if(j<nums.size()){
                    if((nums[i]+nums[j]==target))
                    {
                        ret[0]=i;
                        ret[1]=j;
                        return ret;
                    }
                }
            }
        }

        return ret;
    }
