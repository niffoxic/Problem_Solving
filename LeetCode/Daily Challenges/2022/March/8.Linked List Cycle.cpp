#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode* bunny = head, *turtle = head;
        while (bunny != nullptr && bunny->next != nullptr){
            bunny = bunny->next->next;
            turtle = turtle->next;
            if (bunny == turtle)
                return true;
        }
        return false;
    }
};
