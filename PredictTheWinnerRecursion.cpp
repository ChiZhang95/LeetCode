class Solution {
public:
    bool PredictTheWinner(vector<int>& nums){
        if(nums.size()<3) return true;
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),INT_MIN));
        int player = 1;

        return DP(nums,0,nums.size()-1,player,dp)>=0;
    }
    int DP(vector<int>& nums, int l, int r, int player, vector<vector<int>>& dp){
        if(l==r) return player*nums[l];
        
        if(dp[l][r]!=INT_MIN){
            return dp[l][r];
        }

        int a = player*nums[l]+DP(nums,l+1,r,-player,dp);
        int b = player*nums[r]+DP(nums,l,r-1,-player,dp);     
        dp[l][r] = player*max(player*a,player*b);
        return dp[l][r];
    }
};