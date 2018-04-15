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
    vector<int> rightSideView(TreeNode* root) {
        // Create a vector to contain the values from right view
        vector<int> rightview;
        // if the tree is empty, return an empty vector
        if(!root) {return rightview;}
        
        queue<TreeNode*> q; // Create a queue to contain the node of the tree
        queue<int> dq; // create a syncronized queue to contain the depth of each node
        q.push(root); // initialize q with root
        dq.push(0); // initialize dq with 0 level
        rightview.push_back(root->val); // initialize rightview with the value of the root
        
        // Run until every node has been traversed
        while(!q.empty()){
            TreeNode* node = q.front(); // take the first node in the queue
            int depth = dq.front(); // take out the first depth in the queue
            q.pop();
            dq.pop();
            // std::cout << depth << " " << node->val << endl;
            
            // If this is a new level, add a new space in the rightview vector
            if(depth >= rightview.size()){rightview.push_back(node->val);}
            rightview[depth] = node->val; // overwrite the right view value with nodes in the same level
            
            if(node->left) {
                q.push(node->left); // add left brunch into q
                dq.push(depth+1); // add next depth into dq
            }
            if(node->right) {
                q.push(node->right); // add right brunch into q
                dq.push(depth+1); // add next depth into dq
            }          
        }
        
        return rightview;
    }
};