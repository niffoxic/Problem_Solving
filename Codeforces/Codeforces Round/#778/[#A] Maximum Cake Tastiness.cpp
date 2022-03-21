#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int left = 0, right = 0;
        for(int i = 0, q; i < n; i++){
            cin >> q;
            if (q > left) right = left, left = q;
            else right = max(right, q);
        }
        cout << left + right << "\n";
    }
    return 0;
}
