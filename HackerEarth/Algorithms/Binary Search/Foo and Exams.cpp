#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll process(ll a, ll b, ll c, ll d, ll t){
    return a * ( t * t * t) + b * (t * t) + c * t + d;
}

void solve(int case_no){
    ll a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    ll res = 0;
    ll left = 0, right = 799000;

    while(left < right){
        ll mid = left + (right - left) / 2;
        ll current = process(a, b, c, d, mid);
        if (current == k){
            res = mid + 1;
            break;
        }else if(current > k){
            res = mid;
            right = mid;
        }else left = mid + 1;
    }
    cout << ((res == 0)?0:res - 1) << "\n";
}

int main()
{
    int test_case = 1;
    cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
