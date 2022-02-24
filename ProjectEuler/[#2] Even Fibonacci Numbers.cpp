void solve(int case_no) {
    l = 1, r = 2;
    ll sum = 0;
    while (l <= limit){
        ll temp = l;
        l = r;
        r += temp;
        if (!(temp & 1)) sum += temp;
    }
    cout << sum;
}
