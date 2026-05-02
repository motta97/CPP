class Solution {
public:
int find_max(int i, vector<int>& nums) {
    int n = nums.size();
    int min = 900000000;
    int index = i;

    for (int j = 1; j <= nums[i]; j++) {
        if (i + j == n-1)return n - 1; 
            if (((n - 1) - (j + i) - nums[i + j]) < min)
            {
                min = ((n - 1) - (i + j) - nums[i + j]);
                index = i + j;
            }
        
    }
    return index;
}
int jump(vector<int>& nums) {
    int num_jumbs = 0;
    int i = 0;
    int n = nums.size();
    int iteration = 0;
    while (i < n - 1) {
        if (nums[i] == 0) {
            i++;
        }
        else
            i = find_max(i, nums);
        num_jumbs++;
    }
    return num_jumbs;
}

};