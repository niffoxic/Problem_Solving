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

    static ListNode* middleNode(ListNode* head){
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    static ListNode* reverseLL(ListNode* head){
        ListNode* previous = nullptr;
        while (head != nullptr){
            ListNode* temp = head->next;
            head->next = previous;
            previous = head;
            head = temp;
        }
        head = previous;
        return head;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        right = reverseLL(right);
        while (head != nullptr && right != nullptr){
            if (head->val != right->val)
                return false;
            head = head->next;
            right = right->next;
        }
        return true;
    }
};
