/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root){return;}
        queue<TreeLinkNode*> node;
        queue<int> level;
        node.push(root);
        level.push(0);
        while(!node.empty()){
            TreeLinkNode* curr = node.front();
            int currlv = level.front();
            node.pop();
            level.pop();
            TreeLinkNode* next = node.front();
            int nextlv = level.front();
            
            if(level.empty() || currlv < nextlv){
                curr->next = NULL;
            }
            else{
                curr->next = next;
            }
            if(curr->left){
                node.push(curr->left);
                level.push(currlv+1);
            }
            if(curr->right){
                node.push(curr->right);
                level.push(currlv+1);
            }
        }
    }
};