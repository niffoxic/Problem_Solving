#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fenwick(int index, ll val, vector<ll>& bit, vector<ll>& arr)
{
    ll diff = val - arr[index];
    for(int i = index + 1; i <= arr.size(); i += i & (-i))
        bit[i] += diff;
    arr[index] = val;
}

ll getSum(int index, vector<ll>& bit)
{
    ll res = 0;
    for(int i = index; i > 0; i -= i & (-i))
        res += bit[i];
    return res;
}

int main() {
    int n, q; cin >> n >> q;
    vector<ll> arr(n, 0), bit(n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        ll val; cin >> val;
        fenwick(i, val, bit, arr);
    }
    while (q--)
    {
        int c, left, right; cin >> c >> left >> right;
        if (c == 1) fenwick(left - 1, right, bit, arr);
        else cout << getSum(right, bit) - getSum(left - 1, bit) << "\n";
    }
    return 0;
}
