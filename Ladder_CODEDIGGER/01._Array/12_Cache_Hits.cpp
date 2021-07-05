

int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n, b, m; cin >> n >> b >> m;

        ll arr[m];

        for(int i = 0 ; i < m; i++) cin >> arr[i];

        ll current = -1;
        ll ans = 0;

        for(int i = 0; i < m; i++){
            ll block = arr[i] / b;
            if (block != current){
                ans++;
                current = block;
            }
        }
        print(ans)
    }

    return 0;
}


