#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int sum = 0;
        int k, maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> k; sum += k; maxi = k > maxi? k: maxi;
        }
        double res = (double)(sum - maxi) / (n - 1); res += maxi;
        cout << fixed << setprecision(10) << res << "\n";
    }
    return 0;
}

