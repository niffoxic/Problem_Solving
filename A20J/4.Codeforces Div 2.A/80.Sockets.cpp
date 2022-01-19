#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, arr[50];
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n, greater<>());
    int i = 0, j = k;
    while (i < n && j < m) {
        j += arr[i] - 1;
        i++;
    }
    if (j >= m)
        cout << i;
    else
        cout << -1;
}
