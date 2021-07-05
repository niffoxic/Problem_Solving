
int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    //cin >> test_case;
    while (test_case--)
    {
        int n; cin >> n;
        ll arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        sort(arr, arr + n);
        if (n == 2) print(0)
        else print(min(arr[n - 1] - arr[1], arr[n - 2] - arr[0]))

    }

    return 0;
}
