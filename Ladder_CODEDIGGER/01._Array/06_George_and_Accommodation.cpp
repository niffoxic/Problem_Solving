

int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    int res = 0;
    while (t--)
    {
        int p, q; cin >> p >> q; res += q - p > 1 ?1:0;
    }
    print(res)
    return 0;
}


