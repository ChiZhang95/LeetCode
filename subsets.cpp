class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subset;
        subset.push_back({});
        for(int i=0; i<nums.size(); i++){
            vector<vector<int>> newset = subset;
            for(auto vec : newset){
                vec.push_back(nums[i]);
                subset.push_back(vec);
            }
        }
        return subset;
    }
};