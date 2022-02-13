#include <bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
 
int main() {
    int t; cin >> t;
    while (t--){
        ull sum = 0, n, x, y, k; cin >> n >> x >> y;
        for(int i =  0; i < n; i++) cin >> k, sum += k;
        cout << ((sum + x + y) % 2?"Bob": "Alice") << '\n';
    }
    return 0;
}
