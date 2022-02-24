void solve(int case_no) {
    r = 0;
    for(int i = 999; i >= 900; i--){
        for(int j = 999; j >= 900; j--){
            ti = i * j;
            s = to_string(ti);
            int left = 0, right = s.size() - 1;
            int there = 1;
            while (there && left < right){
                if (s[left] != s[right]) there = 0;
                left++, right--;
            }
            if(there) r = max(r, ti);
        }
    }
    cout << r;
}
