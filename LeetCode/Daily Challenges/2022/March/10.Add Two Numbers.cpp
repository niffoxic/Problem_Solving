class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int extra = 0;
        ListNode *temp, *head = new ListNode();
        temp = head;
        while (l1 or l2 or extra) {
            if (l1) extra += l1->val, l1 = l1->next;
            if (l2) extra += l2->val, l2 = l2->next;
            temp->val = extra % 10;
            extra /= 10;
            if (l1 || l2 || extra) temp = temp->next = new ListNode();
        }
        return head;
    }
};
