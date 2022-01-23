#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m, t;
    cin >> n >> m >> t;
    int arr[m];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (y == -1) x = (n - (t % n) + x) % n;
        else x = ((t % n) + x) % n;
        if (!x) x = n;
        arr[i] = x;
    }
    sort(arr, arr + m);
    for (int i = 0; i < m; i++)
        cout << arr[i] << " ";
    return 0;
}
