#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, k; cin >> n >> k;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    while (k--){
        int t; cin >> t;
        if (binary_search(arr, arr + n, t)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
