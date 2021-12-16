using ll = long long;

ll check(ll mid, ll a, ll b){
    return 1 + log(a)/log(b)+ mid * (log(mid)/log(b));
}

void solve(int case_no)
{
    ll a, n, b;
    while(cin >> a >> n >> b){
        ll left = 1, right = n * b;
        ll res = INT_MAX;
        while (left <= right){
            ll mid = left + (right - left) / 2;
            ll current = check(mid, a, b);
            if (current == n){
                res = mid;
                break;
            }else if (current > n){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        int c = 0;
        left = res, right = res;

        while(true){
            if (check(left--, a, b) == n){
                c++;continue;
            }
            if (check(++right, a, b) == n){
                c++;
                continue;
            }
            break;
        }
        print(c)
    }

}
