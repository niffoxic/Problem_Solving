template <class T>
T __lcm(T _a, T _b){
    return (_a * _b) / __gcd(_a, _b);
}
