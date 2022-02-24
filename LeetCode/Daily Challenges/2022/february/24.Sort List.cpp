struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *side(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *a, ListNode *b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        ListNode *temp;
        if (a->val < b->val) {
            temp = a;
            temp->next = merge(a->next, b);
        } else {
            temp = b;
            temp->next = merge(a, b->next);
        }
        return temp;
    }

    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *mid = side(head);
        ListNode *start = head, *end = mid->next;
        mid->next = nullptr;
        start = sortList(start);
        end = sortList(end);
        ListNode *ans = merge(start, end);
        return ans;
    }
};
