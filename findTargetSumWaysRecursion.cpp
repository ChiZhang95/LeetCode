class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return DP(nums,S,nums.size()-1);
    }
    int DP(vector<int>& nums, int S, int end){
        if(end==-1) return S==0?1:0;
        return DP(nums,S+nums[end],end-1)+DP(nums,S-nums[end],end-1);
    }
};