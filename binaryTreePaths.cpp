/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdio.h>
#include <stdlib.h>
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(!root){
            return paths;
        }
        string path;
        DFS(root,std::to_string(root->val),paths);
        return paths;
    }
    void DFS(TreeNode* root,string path,vector<string>& paths){
        if(!root->left && !root->right){
            paths.push_back(path);
            return;
        }
        if(root->left) DFS(root->left,path + "->" + std::to_string(root->left->val) ,paths);
        if(root->right) DFS(root->right,path + "->" + std::to_string(root->right->val),paths);
    }
};