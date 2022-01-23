#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--)
    {
        int n, s; cin >> n >> s;
        int arr[n + 1]; for(int i = 0; i < n; i++) cin >> arr[i];
        arr[n] = s;
        sort(arr, arr + n + 1);
        int index = -1;
        for(int i = 0; i <= n; i++)
            if (arr[i] == s){
                index = i; break;
            }
        cout << (!index? n: abs(index - (n - index))) << "\n";
    }
    return 0;
}
