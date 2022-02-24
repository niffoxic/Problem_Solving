void solve(int case_no) {
    r = 0;
    for(ll i = 2; i <= 1e6; i++){
        if (!arr[i])
            for(int j = i * 2; j <= 1e6; j += i)
                arr[j] = 1;
        if (!arr[i] && 600851475143 % i == 0) r = max(r, i);
    }
    cout << r;
}
