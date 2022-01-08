#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, m, a, b; cin >> n >> m >> a >> b;
    int res = 0;
    if (b <= m * a){
        int r = n % m;
        res += ((n - r) / m) * b;
        n = r;
        if (b < n * a){
            res += b;
            n = 0;
        }
    }
    res += n * a;
    cout << res;
    return 0;
}
