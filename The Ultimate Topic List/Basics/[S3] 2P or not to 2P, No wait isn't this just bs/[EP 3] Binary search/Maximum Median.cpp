#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, k;
vector<ll> arr;

bool check(ll val) {
    ll pos = 0;
    for (int i = n / 2; i < n; i++) {
        if (val - arr[i] > 0) pos += val - arr[i];
        if (pos > k) return false;
    }
    return pos <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    ll left = 1;
    ll right = 2000000000;
    while (left != right) {
        ll mid = (left + right + 1) / 2;
        if (check(mid))left = mid;
        else right = mid - 1;
    }
    return cout << left, 0;
}
