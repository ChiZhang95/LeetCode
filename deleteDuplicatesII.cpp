class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = new ListNode(0);
        ptr->next = head;
        ListNode* newhead = ptr;
        ListNode* temp;
        while(ptr!=NULL&&ptr->next!=NULL&&ptr->next->next!=NULL){
            if(ptr->next->val==ptr->next->next->val){
                temp = ptr->next->next;
                while(temp!=NULL&&temp->val==ptr->next->val){
                    temp = temp->next;
                }
                ptr->next = temp;
            }
            else ptr = ptr->next;
        }
        return newhead->next;
    }
};