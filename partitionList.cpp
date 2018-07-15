class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        ListNode *temp = new ListNode(0), *ptr=new ListNode(0), *tptr = temp, *newhead = ptr;
        ptr->next = head;
        while(ptr->next!=NULL){
            if(ptr->next->val>=x){
                tptr->next = new ListNode(ptr->next->val);
                tptr = tptr->next;
                ptr->next = ptr->next->next;
            }
            else ptr = ptr->next;
        }
        ptr->next = temp->next;
        return newhead->next;
    }
};