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
