class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k%n == 0) return;
        k = k%n;
        int count = k;       
        vector<int> temp(k,0);
        for(int i=n-1; i>=0; i--){
            if(count>0){
                temp[count-1] = nums[i];
                count--;
            }
           
            if(i<k){
                nums[i] = temp[i];
            }
            else{
                nums[i] = nums[i-k];
            }
        }
    }
};