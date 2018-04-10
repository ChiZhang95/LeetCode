class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsub = nums[0];
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = nums[i] + (dp[i-1]>0?dp[i-1]:0);
            maxsub = max(maxsub,dp[i]);
        }
        return maxsub;
    }
};