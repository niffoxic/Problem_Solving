#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

void build(vector<ull>& arr, vector<ull>& seg, int left, int right, int index)
{
    if (left == right){
        seg[index] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    build(arr, seg, left, mid, index * 2 + 1);
    build(arr, seg, mid + 1, right, index * 2 + 2);
    seg[index] = seg[index * 2 + 1] ^ seg[index * 2 + 2];
}

ull getXOR(vector<ull>& seg, int qleft, int qright, int left, int right, int index)
{
    if (qleft > right || qright < left)
        return 0;
    if (qleft <= left && qright >= right)
        return seg[index];
    int mid = left + (right - left) / 2;
    return getXOR(seg, qleft, qright, left , mid, index * 2 + 1) ^
    getXOR(seg, qleft, qright, mid + 1, right, index * 2 + 2);
}



int main() {
    int n, q; cin >> n >> q;
    vector<ull> arr(n), seg(n * 4); for(int i = 0; i < n; i++) cin >> arr[i];
    build(arr, seg, 0, n - 1, 0);
    while (q--)
    {
        int left, right; cin >> left >> right;
        cout << getXOR(seg, left - 1, right - 1, 0, n - 1, 0) << "\n";
    }
    return 0;
}
