using ull = unsigned long long;

ull add_up(ull n, ull d){
    n /= d;
    return d * n * (n + 1) / 2;
}

int main()
{

    ull n;
    cin >> n;
    int a = 3, b = 5;
    cout << add_up(n - 1, a) + add_up(n - 1, b) - add_up(n - 1, a * b) << "\n";
    return 0;
}
