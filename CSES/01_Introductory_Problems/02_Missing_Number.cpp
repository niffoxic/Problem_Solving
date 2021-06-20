using ll = long long;
using ull = unsigned long long;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while(t--) {
        ll n;
        cin >> n;
        ull sum = 0;
        for(int i = 0; i < n - 1; i++){
            ull curr;
            cin >> curr;
            sum += curr;
        }
        cout << ((n * (n + 1)) / 2) - sum << "\n";
    }

    return 0;
}
