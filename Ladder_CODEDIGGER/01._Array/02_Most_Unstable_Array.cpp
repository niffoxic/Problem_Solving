int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;

        if (n == 1) print(0)
        else print((min(2, n - 1) * m))

    }
    return 0;
}
