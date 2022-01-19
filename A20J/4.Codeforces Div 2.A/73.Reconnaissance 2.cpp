#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, i, a[1000], mini, id1, id2;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    mini = abs(a[n] - a[1]);
    id1 = n;
    id2 = 1;
    for (i = 1; i < n; i++)
        if (abs(a[i + 1] - a[i]) < mini) {
            mini = abs(a[i + 1] - a[i]);
            id1 = i;
            id2 = i + 1;
        }
    cout << id1 << " " << id2;
}
