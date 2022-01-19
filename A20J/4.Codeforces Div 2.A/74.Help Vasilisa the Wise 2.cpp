#include <bits/stdc++.h>

using namespace std;

int main() {
    int r1, r2, c1, c2, d1, d2, a, b, c, d, x;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    x = (d2 - r1);
    c = int((c1 + x) / 2);
    d = r2 - c;
    a = d1 - d;
    b = r1 - a;
    if (a < 1 || a > 9 || b < 1 || b > 9 || c > 9 || c < 1 || d > 9 || d < 1 || a == b || a == c || c == d || a == d ||
        b == d || c == b) {
        cout << "-1";
        return 0;
    }
    return cout << a << " " << b << endl << c << " " << d, 0;
}
