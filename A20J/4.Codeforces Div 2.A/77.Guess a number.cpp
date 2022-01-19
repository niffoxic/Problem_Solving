#include <iostream>

using namespace std;

int main() {
    int l = -2e9, r = 2e9;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int x;
        char c;
        cin >> x >> c;
        if (c == 'N') {
            if (s == ">=") s = "<";
            else if (s == ">") s = "<=";
            else if (s == "<") s = ">=";
            else s = ">";
        }
        if (s == ">") s = ">=", ++x;
        if (s == "<") s = "<=", --x;
        if (s == "<=") r = min(r, x);
        else l = max(l, x);
    }
    if (l <= r) cout << l;
    else puts("Impossible");
    return 0;
}
