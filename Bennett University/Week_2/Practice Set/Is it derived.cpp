#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int i = 0, j = n - 1, curNum = 1;
    if (a[0] != 1) return false;
    while (i <= j) {
        if (a[i] != a[j] || a[i] < curNum || a[i] > curNum + 1) return false;
        if (a[i] != curNum) ++curNum;
        ++i, --j;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << (solve() ? "yes" : "no") << "\n";
    }
    return 0;
}
