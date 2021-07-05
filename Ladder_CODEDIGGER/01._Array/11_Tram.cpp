

int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    int current = 0;
    int ans = 0;
    while (t--)
    {
        int a, b; cin >> a >> b;
        current += (b - a);
        ans = max(ans, current);

    }
    print(ans)
    return 0;
}


