#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, b, x, y;

int main()
{
    int t; cin >> t;
    while (t--){
        cin >> n >> b >> x >> y;
        ll res = 0, current = 0;
        for(int i = 0; i < n; i++){
            current += current + x <= b? x: -y;
            res += current;
        }
        cout << res << "\n";
    }
    return 0;
}
