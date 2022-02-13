#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--){
        int x, y, z; cin >> x >> y >> z;
        if (x < y && x < z) cout << "nothing\n";
        else if (y <= x) cout << "pizza\n";
        else cout << "burger\n";
    }
    return 0;
}

