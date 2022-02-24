#include <bits/stdc++.h>
using namespace std;

ll n, c;

void solve(int case_no) {
    while (cin >> n){
        if (n == 0) break;
        c = 0;
        while (!(n & 1)) c++, n >>= 1;
        if (c) cout << "2^" << c << " ";
        for(int i = 3; i * i <= n; i+=2)
        {
            c = 0;
            while (!(n % i)) c++, n /= i;
            if (c) cout << i << "^" << c << " ";
        }
        if (n > 1) cout << n << "^1";
        cout << "\n";
    }
}
