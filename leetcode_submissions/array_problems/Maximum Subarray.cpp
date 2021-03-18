class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsoFar = nums[0];
        for(auto it: nums)
        {
             sum+=it;
             maxsoFar = max(sum, maxsoFar);
             if(sum<0) sum=0;
        }
        return maxsoFar;
    }
};