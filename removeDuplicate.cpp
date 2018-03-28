#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length == 0){return 0;}
        for(int i=0; i<length-1; i++){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin()+i);
                return removeDuplicates(nums);
            }
        }
        return nums.size();
    }
        
};