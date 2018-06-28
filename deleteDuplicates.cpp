class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        ListNode* temp;
        while(ptr!=NULL&&ptr->next!=NULL){
            if(ptr->next->val == ptr->val){
                temp = ptr->next->next;
                delete ptr->next;
                ptr->next = temp;
                continue;
            }
            ptr = ptr->next;
        }
        return head;
    }
};