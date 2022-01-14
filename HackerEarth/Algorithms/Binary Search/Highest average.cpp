#include <bits/stdc++.h>
using namespace std;

using vpd = vector<pair<double, double>>;
using db = long double;
using ull = unsigned long long;
using ll = long long;

#define pb push_back


int low(vpd &res, db k){
    ull left = 0, right = res.size() - 1;
    ull mid;
    int ans = 0;
    while(left <= right){
        mid = left + (right - left) / 2;
        if (res[mid].first >= k){
            right = mid - 1;
        }else{
            ans = mid;
            left = mid + 1;
        }
    }
    return ans;
}


int main()
{
    int n; cin >> n; ll arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vpd res;
    res.pb({0, 0});
    ll value = 0;
    for(int i = 0; i < n; i++){
        value += arr[i];
        res.pb({value / (i + 1), i + 1});
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        db k; cin >> k;
        cout << low(res, k) << "\n";
    }
    return 0;
}
