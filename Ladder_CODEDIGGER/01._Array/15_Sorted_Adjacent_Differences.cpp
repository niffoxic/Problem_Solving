

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
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);

        int mid = (n - 1) / 2;
        for(int i = 0; i < n; i++){
            if (i & 1) cout << arr[mid + (i + 1)/ 2] << " ";
            else cout << arr[mid - i / 2] << " ";
        }
        print("")
    }

    return 0;
}

