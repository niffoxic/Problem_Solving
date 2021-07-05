

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    int index = 1;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int counts = 0;
        double total = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if (arr[i]) counts++;
            total += arr[i];
        }
 
        cout << setprecision(12);
 
        if (total > 0)
        {
            total /= 100;
            cout << (double)((total / n) * 100) << nn;
        }
        else{
            cout <<0 << nn;
        }
 
    }
    return 0;
}
