#include <bits/stdc++.h>
using namespace std;


int main() {
    long long m, n, s = 0, x = 1, y;
    for (cin >> n >> m; m--; s += (n + y - x) % n, x = y)cin >> y;
    cout << s;
}
