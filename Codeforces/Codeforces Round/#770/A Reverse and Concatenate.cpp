#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        string s, r; cin >> s; r = s;
        reverse(s.begin(), s.end());
        cout << (s == r || k == 0? 1: 2) << "\n";
    }
    return 0;
}
