#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, q; cin >> n >> q;
    unsigned long long arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if (i > 0) arr[i] += arr[i - 1];
    }
    while (q--){
        int a, b; cin >> a >> b;
        cout << arr[b - 1] - (a - 2 >= 0?arr[a - 2]: 0) << "\n";
    }
    return 0;
}

// Using Segment Tree

#include <bits/stdc++.h>
using namespace std;

long long constructSegmentTree(vector<long long>& arr, vector<long long>& tree, int left, int right, int index){
    if (left == right){
        tree[index] = arr[left];
        return arr[left];
    }
    int mid = left + (right - left) / 2;
    tree[index] = constructSegmentTree(arr, tree, left, mid, index * 2 + 1) +
                  constructSegmentTree(arr, tree, mid + 1, right, index * 2 + 2);
    return tree[index];
}

long long getSum(int rangeLeft, int rangeRight, int left, int right, int index, vector<long long>& tree){
    if (right < rangeLeft || rangeRight < left)
        return 0;
    if (rangeLeft <= left && rangeRight >= right)
        return tree[index];
    int mid = left + (right - left) / 2;
    return getSum(rangeLeft, rangeRight, left, mid, index * 2 + 1, tree) +
           getSum(rangeLeft, rangeRight, mid + 1, right, index * 2 + 2, tree);
}

int main(){
    int n, q; cin >> n >> q;
    vector<long long> arr(n), tree(n * 4);
    for(int i = 0; i < n; i++) cin >> arr[i];
    constructSegmentTree(arr, tree, 0, n - 1, 0);
    while (q--){
        int left, right; cin >> left >> right;
        cout << getSum(left - 1, right - 1, 0, n - 1, 0, tree) << "\n";
    }
    return 0;
}
