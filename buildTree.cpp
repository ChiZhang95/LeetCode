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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){return NULL;}
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        int rt=0;
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == postorder[postorder.size()-1]){
                rt = i;
            }
        }
        vector<int> il(inorder.begin(),inorder.begin()+rt);
        vector<int> ir(inorder.begin()+rt+1,inorder.end());
        vector<int> pl(postorder.begin(),postorder.begin()+rt);
        vector<int> pr(postorder.begin()+rt,postorder.end()-1);
        root->left = buildTree(il,pl);
        root->right = buildTree(ir,pr);
        return root;
    }
};