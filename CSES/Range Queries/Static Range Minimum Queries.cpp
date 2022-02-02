#include <bits/stdc++.h>
using namespace std;

int constructTree(int *arr, int *tree, int left, int right, int index)
{
    if (left == right){
        tree[index] = arr[left];
        return arr[left];
    }
    int mid = left + (right - left) / 2;
    tree[index] = min(constructTree(arr, tree, left, mid, index * 2 + 1),
                      constructTree(arr, tree, mid + 1, right, index * 2 + 2));
    return tree[index];
}

int getMin(int qleft, int qright, int left, int right, int index, int *tree){
    if (qright < left || qleft > right)
        return INT_MAX;
    if (left >= qleft && right <= qright)
        return tree[index];
    int mid = left + (right - left) / 2;
    return min(getMin(qleft, qright, left, mid, index * 2 + 1, tree),
               getMin(qleft, qright, mid + 1, right, index * 2 + 2, tree));
}



int main(){
    int n, q; cin >> n >> q;
    int arr[n], tree[4 * n]; for(int i = 0; i < n; i++) cin >> arr[i];
    constructTree(arr, tree, 0, n - 1, 0);
    while (q--){
        int left, right; cin >> left >> right;
        cout << getMin(left - 1, right - 1, 0, n - 1, 0, tree) << "\n";
    }
    return 0;
}
