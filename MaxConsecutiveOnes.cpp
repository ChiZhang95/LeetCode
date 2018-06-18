class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Max=0,count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                Max = max(Max,count);
                count=0;
            }
            count += nums[i];
        }
        Max = max(Max,count);
        return Max;
    }
};