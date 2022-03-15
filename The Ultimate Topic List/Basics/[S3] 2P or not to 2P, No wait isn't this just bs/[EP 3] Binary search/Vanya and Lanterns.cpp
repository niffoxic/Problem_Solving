#include <bits/stdc++.h>

using namespace std;

#define template_size 100010
using ll = long long;
ll arr[template_size];


int main() {
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    ll res = max(arr[0], l - arr[n - 1]) * 2;
    for (int i = 1; i < n; i++) res = max(res, arr[i] - arr[i - 1]);
    return cout << setprecision(10) << (double) res / 2.0, 0;
}
