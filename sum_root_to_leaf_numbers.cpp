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
    int sumNumbers(TreeNode* root) {
        if(!root){return 0;} // For a empty tree, return 0
        int sum = dfs(root,0);
        return sum;
    }
    int dfs(TreeNode* root,int level){
        if(!root){return 0;}
        int left = 0,right = 0, sum = 0;
        if(root->left)left = dfs(root->left, level*10 + root->val);
        if(root->right) right = dfs(root->right, level*10 + root->val);
        sum = left + right;
        if(!root->left && !root->right){sum = level*10 + root->val;}
        return sum;
    }
};