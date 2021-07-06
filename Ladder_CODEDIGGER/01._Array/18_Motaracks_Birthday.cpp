

int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    cin >> test_case;
    while (test_case--)
    {
        int n; cin >> n;
        int mn = INT_MAX, mx = INT_MIN;

        int arr[n]; for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++){
            if (i > 0 && arr[i - 1] == -1 && arr[i] != -1
            || (i < n - 1 && arr[i + 1] == -1 && arr[i] != -1))
            {
                mn = min(mn, arr[i]);
                mx = max(mx, arr[i]);
            }
        }

        int k = (mx + mn) / 2;
        int max_abs = 0;
        for(int i = 0; i < n; i++){
            if (arr[i] == -1)
                arr[i] = k;
            if (i)
                max_abs = max(max_abs, abs(arr[i] - arr[i - 1]));
        }

        cout << max_abs << " " << k << nn;
    }

    return 0;
}
