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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        vector<vector<int>> t;
        
        if(!root){return t;}
        q.push(root);
        
        while(!q.empty()){
            vector<int> currlevel;
            int length = q.size();
            
            for(unsigned int i=0; i<length; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                currlevel.push_back(curr->val);
                if(curr->left !=NULL){q.push(curr->left);}
                if(curr->right!=NULL){q.push(curr->right);}
            }
            t.push_back(currlevel);
        }
        return t;
    }
};