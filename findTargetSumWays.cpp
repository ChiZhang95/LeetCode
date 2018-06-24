class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int,int> dp;
        dp[nums[0]] += 1;
        dp[-nums[0]] += 1;
        for(int i=1; i<nums.size(); i++){
            unordered_map<int,int> curr;
            for(auto elem : dp){
                curr[elem.first+nums[i]] += elem.second;
                curr[elem.first-nums[i]] += elem.second;
            }
            dp = curr;
        }
        return dp[S];
    }
};