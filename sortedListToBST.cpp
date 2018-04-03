/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){return NULL;}
        return buildtreeDFS(head,NULL);
    }
    TreeNode* buildtreeDFS(ListNode* head,ListNode* tail){
        if(head == tail){return NULL;}
        if(head->next == tail){
            TreeNode* tree = new TreeNode(head->val);
            return tree;
        }
        ListNode* mid = head;
        ListNode* temp = head;
        while(temp != tail && temp->next != tail){
            mid = mid->next;
            temp = temp->next->next;
        }
        TreeNode* thead = new TreeNode(mid->val);
        thead->left = buildtreeDFS(head,mid);
        thead->right = buildtreeDFS(mid->next,tail);
        return thead;
    }
};