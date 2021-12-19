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
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if (!heada || !headb) return nullptr;
        ListNode* a = heada;
        ListNode* b = headb;
        while (a != b){
            a = a == nullptr? headb: a->next;
            b = b == nullptr? heada: b->next;
        }
        return a;
    }
};
