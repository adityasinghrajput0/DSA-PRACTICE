class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
};