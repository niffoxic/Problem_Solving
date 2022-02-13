#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll i, j,  n = 100000, t; cin >> t;
    vector<ll> arr(100005, 1);
    set<ll> primes;
    arr[0] = 0, arr[1] = 0;
    for (i = 2; i <= n; i++) {
        if (arr[i] == 1) {
            primes.insert(i);
            for (j = i; j <= 100000; j += i)
                arr[j] = 0;
        }
    }
    while (t--) {
        cin >> n;
        if (n == 3) {
            cout << n << "\n";
            continue;
        }
        auto iter = primes.lower_bound(n);
        iter--;
        cout << (n % 2) + ((n - (n % 2)) * (*iter)) / 2 << '\n';
    }
    return 0;
}
