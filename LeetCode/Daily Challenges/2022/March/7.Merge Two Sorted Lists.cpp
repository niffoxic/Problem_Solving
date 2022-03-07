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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list2 == nullptr)
            return list1;
        if (list1 == nullptr)
            return list2;

        if (list1->val > list2->val)
            swap(list1, list2);
        ListNode* res = list1;

        while(list1 != nullptr && list2 != nullptr){
            ListNode* temp = nullptr;
            while (list1 != nullptr && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return res;
    }
};
