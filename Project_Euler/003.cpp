using ull = unsigned long long;

int main()
{
    ull n;
    cin >> n;
    
    while (!(n % 2)) n /= 2;
    int diff = 3;
    while (diff * diff <= n){
        if (!(n % diff)) n /= diff;
        else diff += 2;
    }
    cout << ((n == 1)? 2: n) << "\n";
    
    return 0;
}
