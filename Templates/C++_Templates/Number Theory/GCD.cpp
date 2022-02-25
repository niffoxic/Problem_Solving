template <class T>
T gcd(T _a, T _b){
    if (_b == 0) return _b;
    return (_b, _a % _b);
}
