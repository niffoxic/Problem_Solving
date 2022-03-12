/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> mp;
        Node *point = head;
        while (point) {
            mp[point] = new Node(point->val);
            point = point->next;
        }
        point = head;
        while (point) {
            mp[point]->next = mp[point->next];
            mp[point]->random = mp[point->random];
            point = point->next;
        }
        return mp[head];
    }
};
