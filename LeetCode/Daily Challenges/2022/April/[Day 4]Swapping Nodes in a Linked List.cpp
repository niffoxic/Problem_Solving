#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        ListNode *right = nullptr;
        ListNode *at;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            if (right != nullptr) right = right->next;
            if (!--k) at = p, right = head;
        }
        swap(at->val, right->val);
        return head;
    }
};
