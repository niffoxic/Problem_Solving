ll poly(ll a, ll b, ll c, ll x){
    return a * (x * x) + b * x + c;
}

void solve(int case_no){
    ll a, b, c, k; cin >> a >> b >> c >> k;
    ll left = 0, right = 1e5;
    ll res = INT_MAX;
    while(left <= right){
        ll mid = left + (right - left) / 2;
        ull current = poly(a, b, c, mid);
        if (current == k){
            res = mid;
            break;
        }else if (current > k){
            right = mid - 1;
            res = mid;
        }
        else left = mid + 1;
    }
    print(res)
}
