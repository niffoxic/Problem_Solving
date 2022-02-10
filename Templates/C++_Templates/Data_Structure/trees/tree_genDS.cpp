class Node{
public:
    long long key{};
    Node *left{};
    Node *right{};
    explicit Node(int k);
};

Node::Node(int k) {
    key = k;
    left = right = nullptr;
}

void inorder(Node *root){
    if (root != nullptr){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node *root){
    if (root != nullptr){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if (root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
