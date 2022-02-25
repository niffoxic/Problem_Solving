template <class T>
T gcd(T _a, T _b){
    if (_b == 0) return _b;
    return (_b, _a % _b);
}


template <class T>
T gcd (T _a, T _b) {
    while (_b) {
        _a %= _b;
        swap(_a, _b);
    }
    return _a;
}

template <class T>
T __GCD(T _a, T _b){
    if (!_a || !_b) return _a | _b;
    unsigned shift = __builtin_ctz(_a | _b);
    _a >>= __builtin_ctz(_a);
    do{
        _b >>= __builtin_ctz(_b);
        if (_a > _b) swap(_a, _b);
        _b -= _a;
    } while (_b);
    return _a << shift;
}
