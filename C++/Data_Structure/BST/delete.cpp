struct Node{
    int key;
    struct Node *left, *right;
    explicit Node(int k){
        key = k;
        left = right = nullptr;
    }
};

Node* getSuccessor(Node* curr){
    curr = curr->right;
    while (curr != nullptr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}

Node* delNode(Node* root, int key){
    if (root == nullptr) return root;
    if (root->key > key){
        root->left = delNode(root->left, key);
    }else if (root->key < key){
        root->right = delNode((root->right, key);)
    }else{
        if (root->left == nullptr){
            Node *temp = root->right;
            delete root;
            return temp;
        }else if (root->right == nullptr){
            Node *temp = root->left;
            delete root;
            return temp;
        }else{
            Node* suc = getSuccessor(root);
            root->key = suc->key;
            root->right = delNode(root->right, suc->key);
        }
        return root;
    }
}
