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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0,0,inorder.size()-1,preorder,inorder);
    }
    TreeNode* helper(int prestart, int instart, int inend, vector<int> preorder, vector<int> inorder){
        if(prestart > preorder.size() - 1 || instart > inend){
            return NULL;
        }
        TreeNode* t = new TreeNode(preorder[prestart]);
        int pos = 0;
        for(int i=instart; i<=inend; i++){
            if(inorder[i] == t->val){
                pos = i;
            }
        }
        t->left = helper(prestart+1, instart, pos-1, preorder, inorder);
        t->right = helper(prestart+pos-instart+1, pos+1, inend,preorder, inorder);
        return t;
    }
};