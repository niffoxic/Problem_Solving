#define print(x) cout << (x) << nn;


void solve(int case_no)
{
    ll n, a, b; cin >> n >> a >> b;
    ll x = (n * b) / (a + b);
    ll y = x + 1;
    ll res = (a * (x * x) + b * ((n - x) * (n - x)) < a * (y * y) + b * ((n - y) * (n - y)))?
            a * (x * x) + b * ((n - x) * (n - x)):a * (y * y) + b * ((n - y) * (n - y));
    print(res);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
