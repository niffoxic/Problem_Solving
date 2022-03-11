#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        int n = 0;
        ListNode *temp = head;

        while (temp) {
            n++;
            if (!temp->next) break;
            temp = temp->next;
        }
        if (n <= 1) return head;
        k = k % n;
        if (k == 0) return head;
        temp->next = head;
        temp = head;
        for (int i = 0; i < n - k - 1; i++) temp = temp->next;
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};
