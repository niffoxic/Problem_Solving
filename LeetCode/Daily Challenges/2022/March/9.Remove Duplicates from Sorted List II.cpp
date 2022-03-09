#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    static ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        auto *res = new ListNode(-101, head);
        ListNode *temp1 = res;
        ListNode *temp2;
        while (head && head->next) {
            temp2 = head->next;
            if (head->val == temp2->val) {
                while (temp2 && head->val == temp2->val) temp2 = temp2->next;
                temp1->next = temp2;
                head = temp2;
            } else head = head->next, temp1 = temp1->next;
        }
        return res->next;
    }
};
