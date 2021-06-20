using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while(t--) {
        int n;
        cin >> n;
        ll arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        ll res = 0;
        for(int i = 1; i < n; i++){
            ll adding = (arr[i - 1] > arr[i])? (arr[i - 1] - arr[i]):0;
            res += adding;
            arr[i] += adding;
        }
        cout << res << "\n";

    }

    return 0;
}
