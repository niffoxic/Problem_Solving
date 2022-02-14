#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int m; cin >> m;
    while (m--){
        int left, right; cin >> left >> right;
        cout << upper_bound(arr, arr + n, right) - lower_bound(arr, arr + n, left) << " ";
    }
    return 0;
}
