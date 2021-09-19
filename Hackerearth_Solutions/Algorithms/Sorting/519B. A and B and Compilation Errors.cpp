void solve(int case_no){ // thru hashin
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

void solve2(int case_no){
    int n; cin >> n;
    int s1[3] = {0, 0, 0};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n - i; j++){
            int t; cin >> t;
            s1[i] += t;
        }
    }
    cout << s1[0] - s1[1] << nn << s1[1] - s1[2] << nn;
}
