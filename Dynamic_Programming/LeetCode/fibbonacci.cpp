// can be optimsed easily but too basic question so I didnt bother to do that
using ull = unsigned long long;

ull fib(ull n, ull dp[]){
    if (n == 1 || n == 2) return 1;
    if (n == 0) return 0;
    if (dp[n]) return dp[n];
    ull ans = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n] = ans;
}
