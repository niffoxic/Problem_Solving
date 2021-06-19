using ull = unsigned long long;


int main()
{
    ull n;
    cin >> n;
    ull sm = 0, x = 0, y = 1;
    while (y <= n){
        if (y % 2 == 0) sm += y;
        ull temp = y;
        y += x;
        x = temp;
    }
    cout << sm << "\n";
    return 0;
}
