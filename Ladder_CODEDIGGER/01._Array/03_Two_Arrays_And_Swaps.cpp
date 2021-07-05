

int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        int a[n], b[n];

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        sort(a, a + n);
        sort(b, b + n);

        int i = 0, j = n - 1;

        while (k && i < n && j >= 0){
            if (a[i] < b[j]){
                a[i] = b[j];
                i++, j--; k--;
            }else break;
        }
        ll ans = 0; for(int l = 0; l < n; l++) ans += a[l];
        print(ans)
    }
    return 0;
}

