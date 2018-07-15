class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode *ptr, *sentinal=new ListNode(0), *M, *temp, *prev, *tail;
        sentinal->next = head;
        ptr = sentinal;
        int count=1;
        while(count <= n){
            if(count >= m){
                temp = new ListNode(ptr->next->val);
                if(count == m){
                    M = ptr;
                    tail = temp;
                }
                temp->next = prev;
                prev = temp;
            }
            count++;
            ptr = ptr->next;
        }
        M->next = temp;
        tail->next = ptr->next;
        return sentinal->next;
    }
};