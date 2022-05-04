#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int arr[n + 1];
        for(int i = 1; i <= n; i++) cin >> arr[i];
        sort(arr + 1, arr + n + 1, greater<>());
        int res = k - 1;
        for(int i = k; i <= n && arr[k] <= arr[i]; i++) res++;
        cout << res << "\n";
    }
    return 0;
}
