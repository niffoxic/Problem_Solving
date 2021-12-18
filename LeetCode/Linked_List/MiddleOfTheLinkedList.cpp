#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int t = 0;
        ListNode* res = head;
        while (head != nullptr){
            t++;
            if (!(t % 2))
                res = res->next;
            head = head->next;
        }
        return res;
    }
};
