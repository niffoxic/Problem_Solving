#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll sum1 = 0, sum2 = 0;
        ll n, c0, c1; cin >> n >> c0 >> c1;
        ll arr[n], arr1[n], arr2[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i % 2 == 0) arr1[i] = 0, arr2[i] = 1;
            else arr1[i] = 1, arr2[i] = 0;
            if ((arr[i] - arr1[i]) == 1) sum1 += c1;
            else if ((arr[i] - arr1[i]) == -1) sum1 += c0;
            if ((arr[i] - arr2[i]) == 1) sum2 += c1;
            else if ((arr[i] - arr2[i]) == -1) sum2 += c0;
        }
        cout << min(sum1, sum2) << "\n";
    }
    return 0;
}
