#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    int count = 0, t = 1;
    for (int i = 0; i < n; i++) {
        int l = 0, r = 0;
        cin >> l >> r;
        count += ((l - t) % x) + (r - l + 1);
        t = r + 1;
    }
    cout << count;
    return 0;
}
