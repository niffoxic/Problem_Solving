class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* last = nullptr;
        while (head != nullptr){
            ListNode* temp = head->next;
            head->next = last;
            last = head;
            head = temp;
        }
        head = last;
        return head;
    }
};
