#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int res = INT_MAX;
    int left = 0, right = n;
    while (left * 2 <= n){
        if ((left + right) % m == 0)
            res = min(res, left + right);
        left++;
        right -= 2;
    }
    cout << (res==INT_MAX?-1: res);
    return 0;
}
