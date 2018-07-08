class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0) return head;
        int length=0,count=0;
        ListNode* ptr = head,*prev=head,*newhead;
        while(ptr!=NULL){
            ptr = ptr->next;
            length++;
        }
        if(k%length==0) return head;
        ptr = head;
        while(ptr->next!=NULL){
            count++;
            ptr = ptr->next;
            if(count<length-k%length) prev = prev->next;
            if(count==length - k%length) newhead = ptr;
            
        }
        prev->next = NULL;
        ptr->next = head;
        
        
        return newhead;
    }
};