class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j;
        while(i<nums.size()){
            if(nums[i] == 0){
                j=i;
                while(nums[j] == 0){
                    j++;
                    if(j == nums.size()) return;
                }
                swap(nums[i],nums[j]);
            }
            i++;
        }
    }
};