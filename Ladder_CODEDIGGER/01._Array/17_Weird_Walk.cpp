
int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    cin >> test_case;
    while (test_case--)
    {
        ll n; cin >> n;
        ll a[n], b[n];

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        ll res = 0, s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++){
            if (a[i] == b[i] && s1 == s2) res += a[i];
            s1 += a[i];
            s2 += b[i];
        }
        print(res)
    }

    return 0;
}
