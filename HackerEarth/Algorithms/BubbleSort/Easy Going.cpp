#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m; int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        int left = accumulate(arr, arr + n - m, 0), right = accumulate(arr + m, arr + n, 0);
        cout << right - left << "\n";
    }
    return 0;
}
