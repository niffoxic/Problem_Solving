
// Calculate pow with mod
 const int mod = 1e9 + 7;
template<class T>
T pow_mod(T x, T n, T m){
    if (!n) return 1;
    T temp = pow_mod(x, n / 2, m);
    if (n & 1) return temp * temp * x % mod;
    return temp * temp % mod;
}
