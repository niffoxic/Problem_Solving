#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            int l; cin >> l; sum += l;
        }
        cout << (sum / n > k?  sum / (k + 1) - n + 1: 0) << "\n";
    }
    return 0;
}
