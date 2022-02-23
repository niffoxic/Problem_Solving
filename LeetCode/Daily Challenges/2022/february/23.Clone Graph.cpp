class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        unordered_map<int, Node*> visited;
        return clone(node , visited);
    }

    Node *clone(Node* node, unordered_map<int,Node*>& visited)
    {
        Node *new_node = new Node(node->val);
        visited.insert({node->val,new_node});
        for(Node *n : node->neighbors){
            auto it = visited.find(n -> val);
            if(it == visited.end())
            {
                Node *cn = clone(n, visited);
                new_node->neighbors.push_back(cn);
            }
            else
                new_node->neighbors.push_back(it -> second);
        }
        return new_node;
    }
};
