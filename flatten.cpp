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
private:
    TreeNode* dfs(TreeNode* root){
        // if tree is empty, return
        if(!root){return NULL;}
        // store root, left,right
        TreeNode* temp = root, *left = root->left, *right = root->right;
        // remove left brunch
        root->left = NULL;
        // left brunch
        if(left){
            temp = dfs(left);
            root->right = left;
            root = temp;
        }
        // right brunch
        if(right){
            temp = dfs(right);
            root->right = right;
        }
        return temp;
    }
public:
    void flatten(TreeNode* root) {
        dfs(root);
    }
};