#include <bits/stdc++.h>
using namespace std;


void build(vector<int>& arr, vector<int>& seg, int left, int right, int index)
{
    if (left == right){
        seg[index] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    build(arr, seg, left, mid, index * 2 + 1);
    build(arr, seg, mid + 1, right, index * 2 + 2);
    seg[index] = min(seg[index * 2 + 1], seg[index * 2 + 2]);
}

int getMin(vector<int>& seg, int qleft, int qright, int left, int right, int index)
{
    if (qleft > right || qright < left)
        return INT_MAX;
    if (qleft <= left && qright >= right)
        return seg[index];
    int mid = left + (right - left) / 2;
    return min(getMin(seg, qleft, qright, left, mid, index * 2 + 1),
               getMin(seg, qleft, qright, mid + 1, right, index * 2 + 2));
}

void updateMin(vector<int>&seg, int position, int val, int index, int left, int right){
    if (left == right){
        seg[index] = val;
        return;
    }
    int mid = left + (right - left) / 2;
    if (position <= mid)
        updateMin(seg, position, val, index * 2 + 1, left, mid);
    else updateMin(seg, position, val, index * 2 + 2, mid + 1, right);
    seg[index] = min(seg[index * 2 + 1], seg[index * 2 + 2]);
}

int main() {
    int n, q; cin >> n >> q;
    vector<int> arr(n), seg(n * 4); for(int i = 0; i < n; i++) cin >> arr[i];
    build(arr, seg, 0, n - 1, 0);
    while (q--)
    {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1){
            updateMin(seg, l - 1, r, 0, 0, n - 1);
            arr[l - 1] = r;
        }
        else cout << getMin(seg, l - 1, r - 1, 0, n - 1, 0) << "\n";
    }
    return 0;
}
