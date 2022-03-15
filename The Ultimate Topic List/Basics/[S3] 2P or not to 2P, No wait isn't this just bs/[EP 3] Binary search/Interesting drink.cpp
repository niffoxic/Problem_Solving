#include <bits/stdc++.h>
using namespace std;

#define template_size 100010
using ll = long long;
ll arr[template_size];


int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int q; cin >> q;
    while (q--){
        int m; cin >> m;
        cout << (upper_bound(arr, arr + n, m) - arr) << "\n";
    }
    return 0;
}



