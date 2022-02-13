#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--){
        int n, a; cin >> n >> a;
        cout << min(n - a, a) << "\n";
    }
    return 0;
}

