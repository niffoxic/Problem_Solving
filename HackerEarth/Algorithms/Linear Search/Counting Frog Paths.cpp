#include<bits/stdc++.h>
using namespace std;

using ll = long long;
# define print(x) cout << (x) << "\n";

int main() {
    int x, y, sq, t; cin >> x >> y >> sq >> t;
    t -= (x + y);
    if (t < 0) print(0)
    else
    {
        t++, sq++;
        ll res = 0;
        res = (t < sq)? (t * (t + 1)) / 2:
              (t < 2 * sq)? (sq * sq) - ((2 * sq - (t + 1)) * ((2 * sq - (t + 1)) + 1)) / 2:
              sq * sq;

        print(res)
    }
    return 0;
}
