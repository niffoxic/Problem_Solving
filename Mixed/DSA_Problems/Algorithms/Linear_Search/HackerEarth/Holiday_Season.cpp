// O(N^2) not the best solution
void solve(int case_no)
{
    int n; str s1; cin >> n >> s1;
    int al[26]{};
    int res = 0;
    for(int i = 0; i < n; i++){
        int current = 0;
        for(int j = i + 1; j < n; j++){
            if (s1[i] == s1[j]){
                res += current;
            }
            current += al[s1[j] - 'a'];
        }
        al[s1[i] - 'a']++;
    }
    print(res)
}
