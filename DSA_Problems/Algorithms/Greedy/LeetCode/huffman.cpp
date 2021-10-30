#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string res[26] = { "" };

struct Node {
    int freq;
    char ch;
    Node* left, * right;
    Node(char c, int fq, Node* l = nullptr, Node* r = nullptr) {
        this->freq = fq;
        this->ch = c;
        this->left = l;
        this->right = r;
    }
};

struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void decode(Node* root, string str) {
    if (root->ch != '$') {
        res[root->ch - 'a'] = str;
        return;
    }
    decode(root->left, str + '0');
    decode(root->right, str + '1');
}

void encode(vector<char>& arr, vector<int>& freq, int n)
{
    priority_queue<Node*, vector<Node*>, compare> huff;
    for (int i = 0; i < n; i++)
        huff.push(new Node(arr[i], freq[i]));
    while (huff.size() > 1) {
        Node* left = huff.top(); huff.pop();
        Node* right = huff.top(); huff.pop();
        Node* node = new Node('$', left->freq + right->freq, left, right);
        huff.push(node);
    }
    decode(huff.top(), "");
}


int main() {
    vector<char> arr;
    vector<int> freq;
    string temp;
    while (cin >> temp)
    {
        arr.push_back(temp[0]);
        freq.push_back(stoi(temp.substr(2, temp.size())));
    }
    encode(arr, freq, arr.size());
    for (int i = 0; i < 26; i++)
        if (res[i] != "")
            cout << char('a' + i) << ":" << res[i] << "\n";
    return 0;
}
