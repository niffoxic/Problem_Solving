int hex(int n){
    int ans = 0;
    while (n){
        int rem = n % 16;
        ans += rem;
        n = n / 16;
    }
    return ans;
}

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b % a, a);
}

void solve(int case_no)
{
    int l, r; cin >> l >> r;
    int res = 0;
    for(int i = l;i <= r; i++){
        int val = hex(i);
        if (gcd(i, val) > 1) res++;
    }
    print(res)
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
