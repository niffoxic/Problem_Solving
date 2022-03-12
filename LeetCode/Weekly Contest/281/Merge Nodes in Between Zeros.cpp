/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *res = new ListNode(-1), *left = res, *right = head->next, *begin = head;
        while (right) {
            ListNode *end = right->next, *temp = right;
            while (end->val != 0) {
                temp->val += end->val;
                end = end->next;
            }
            temp->next = nullptr;
            left->next = temp;
            left = left->next;

            begin = end;
            right = end->next;
        }
        left->next = NULL;
        return res->next;
    }
};
