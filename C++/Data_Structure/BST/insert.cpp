struct Node{
    int key;
    struct Node *left, *right;
    explicit Node(int k){
        key = k;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int key){
    if (root == nullptr) return new Node(key);
    if (root->key < key)
        root->right = insert(root->right, key);
    else if (root->key > key)
        root->left = insert(root->left, key);
    return root;
}
