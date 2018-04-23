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
    int findTilt(TreeNode* root) {
        if(!root){return 0;}
        return tilt(root) + findTilt(root->left) + findTilt(root->right);
    }
    int tilt(TreeNode* root){
        return abs(sumnodes(root->left) - sumnodes(root->right));
    }
    int sumnodes(TreeNode* root){
        if(!root){return 0;}
        if(!root->left && !root->right){return root->val;}
        return root->val + sumnodes(root->left) + sumnodes(root->right);
    }
};