#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
#define print(x) cout << x << nn;


int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    while (test_case--)
    {
        ull n, k; cin >> n >> k;
        unordered_map<ull, ull> res;
        for(int i = 0; i < n; i++){
            ull st; cin >> st;
            res[st % k]++;
        }
        ull ans = 0;
        for(auto i: res){
            ans += i.s * 1ULL * (i.s - 1);
        }
        print(ans)
    }
 
    return 0;
}
