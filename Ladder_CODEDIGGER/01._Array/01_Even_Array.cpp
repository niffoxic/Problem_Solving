

int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int even = 0, odd = 0, needed = 0;
        int arr[n]; for(int i = 0; i < n; i++){
            cin >> arr[i];
            if (arr[i]&1) odd++;
            else even++;
            if (arr[i] % 2 != i % 2) needed++;
        }

        if (n % 2 == 0 && odd != even) print(-1)
        else if (n % 2 && odd + 1 != even) print(-1)
        else{
            if (needed) print(needed / 2)
            else print(0)
        }

    }
    return 0;
}
