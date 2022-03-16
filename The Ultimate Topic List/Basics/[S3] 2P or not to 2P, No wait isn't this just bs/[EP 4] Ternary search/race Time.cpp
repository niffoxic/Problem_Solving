#include <bits/stdc++.h>
using namespace std;

#define template_size 100009
int n, k;

int s[template_size], d[template_size];

double f(double t) {
    double mx = INT_MIN, mn = INT_MAX;
    for (int i = 0; i < n; i++) mx = max(mx, s[i] * t + d[i]), mn = min(mn, s[i] * t + d[i]);
    return mx - mn;
}

double ternary_search(double l, double r) {
    double eps = 1e-10;
    while (r - l > eps) {
        double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        double f1 = f(m1), f2 = f(m2);
        if (f1 > f2) l = m1;
        else r = m2;
    }
    return f(l);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> s[i] >> d[i];
    return cout << fixed << setprecision(6) << ternary_search(0, k), 0;
}
