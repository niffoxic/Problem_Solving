#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int res = 0;
    sort(arr, arr + n);
    for(int i = 1; i < n - 1 && !res; i++) if (arr[i] + arr[i - 1] > arr[i + 1]) res = 1;
    return cout << (res == 1?"YES": "NO"), 0;
}
