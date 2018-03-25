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
    void levelOrder(vector<vector<int>> &t, TreeNode* root, int level){
        if(!root){return;} // If onr path is traversed, return.
        if(t.empty() || level > t.size()-1){ // if t is just initialized or enter a new level, create a new vector to contain nodes at this level.
            t.push_back(vector<int>());
        }
        t[level].push_back(root->val); // put value in this node into t.
        levelOrder(t,root->left,level+1); // enter left brunch
        levelOrder(t,root->right,level+1); // enter right brunch
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> t;
        levelOrder(t,root,0);
        reverse(t.begin(),t.end()); // reverse the matrix an get the order we want
        return t;
    }
};