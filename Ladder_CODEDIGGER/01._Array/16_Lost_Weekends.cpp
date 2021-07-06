

int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    cin >> test_case;
    while (test_case--)
    {
        int total = 0, p;
        for(int i = 0; i < 5; i++){
            int current; cin >> current; total += current;
        }cin >> p;
        print((total * p > 24 * 5?Yes:No))
    }

    return 0;
}
