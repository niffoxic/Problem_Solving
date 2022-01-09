#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, t, res = 0; cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> t, res += t;
    cout << (d >= res + 10 * (n - 1)?(d - res) / 5: -1);
    return 0;
}
