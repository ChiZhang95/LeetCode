/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){return NULL;}
        if(len == 1){return new TreeNode(nums[0]);}
        TreeNode* t = new TreeNode(nums[len/2]);
        vector<int> l = vector<int> (nums.begin(),nums.begin()+len/2);
        vector<int> r = vector<int> (nums.begin()+len/2+1,nums.end());  
        t->left = sortedArrayToBST(l);
        t->right = sortedArrayToBST(r);
        return t;
    }
};