void solve(int case_no){
    int n; cin >> n;
    umi a1, a2;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        a1[t]++;
    }
    for(int i = 0; i < n - 1; i++){
        int t; cin >> t;
        a2[t]++;
        a1[t]--;
    }
    for(int i = 0; i < n - 2; i++){
        int t; cin >> t;
        a2[t]--;
    }
    for(auto i: a1) if (i.second > 0){
        cout << i.first << nn; break;
    }
    for(auto i: a2) if (i.second > 0){
        cout << i.first << nn; break;
    }
}
