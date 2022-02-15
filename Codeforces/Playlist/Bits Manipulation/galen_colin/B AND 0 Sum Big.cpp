#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
 
int main()
{
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        long long res = 1;
        for(int i = 0; i < k; i++)
            res = (res * n) % mod;
        cout << res << "\n";
    }
}
