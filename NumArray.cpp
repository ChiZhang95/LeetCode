class NumArray {
private:
    vector<int> vec;
    int len;
public:
    NumArray(vector<int> nums) {
        len = nums.size();
        vec = vector<int> (len+1,0);
        for(int i=1; i<=len; i++){
            vec[i] = vec[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return vec[j+1] - vec[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */