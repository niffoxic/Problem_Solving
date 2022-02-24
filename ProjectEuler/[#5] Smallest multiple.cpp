void solve(int case_no) {
    r = 1;
    for(ll i = 1; i <= 20; i++)
        r *= i / __gcd(i, r);
    cout << r;
}
