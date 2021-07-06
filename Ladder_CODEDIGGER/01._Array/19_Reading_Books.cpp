
int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    // cin >> test_case;
    while (test_case--)
    {
        int n, k; cin >> n >> k;
        vi times[4], sums[4];

        for(int i = 0; i < n; i++){
            int t, a, b; cin >> t >> a >> b;
            times[2 * a + b].pb(t);
        }

        for(int i = 0; i < 4; i++){
            sort(times[i].begin(), times[i].end());
            sums[i].pb(0);
            for(auto it: times[i]) sums[i].pb(sums[i].back() + it);
        }

        int ans = INT_MAX;

        for(int i = 0; i < min(k + 1, int(sums[3].size())); i++){
            if (k - i < int(sums[1].size()) && k - i < int(sums[2].size())){
                ans = min(ans, sums[3][i] + sums[1][k - i] + sums[2][k - i]);
            }
        }
        print((ans == INT_MAX?-1:ans))
    }

    return 0;
}
