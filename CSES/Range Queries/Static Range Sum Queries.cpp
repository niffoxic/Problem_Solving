#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, q; cin >> n >> q;
    unsigned long long arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if (i > 0) arr[i] += arr[i - 1];
    }
    while (q--){
        int a, b; cin >> a >> b;
        cout << arr[b - 1] - (a - 2 >= 0?arr[a - 2]: 0) << "\n";
    }
    return 0;
}
