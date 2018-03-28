class NumArray {
private:
    vector<int> vec;
    int len;
public:
    NumArray(vector<int> nums) {
        if(nums.size()>0){
            len = nums.size();
            vec = vector<int> (len*2,0);
            for(int i=len; i<2*len; i++){
                vec[i] = nums[i-len];
            }
            for(int j = len-1; j>0; j--){
                vec[j] = vec[j*2] + vec[j*2+1];
            }
        }
    }
    
    void update(int i, int val) {
        int diff = val - vec[i+len];
        int j = i+len;
        while(j>0){
            vec[j] += diff;
            j /= 2;
        }
    }
    
    int sumRange(int i, int j) {
        int sum=0;
        i += len;
        j += len;
        while(i<=j){
            if(i%2==1){
                sum += vec[i];
                i++;
            }
            if(j%2==0){
                sum += vec[j];
                j--;
            }
            i /= 2;
            j /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */