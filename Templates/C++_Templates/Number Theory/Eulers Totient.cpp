
template <class T>
T sqPHI(T _n){
    T _res = _n;
    for(T i = 2; i * i <= _n; i++){
        if (_n % i == 0){
            while (_n % i == 0) _n /= i;
            _res -= _res / i;
        }
    }
    if (_n > 1) _res -= _res / _n;
    return _res;
}

template <class T>
vector<T> SievePHI(T _n){
    vector<T> phi(_n + 1);
    for(T i = 0; i <= _n; i++) phi[i] = i;
    for(T i = 2; i <= _n; i++)
        if (phi[i] == i)
            for(T j = i; j <= _n; j += i)
                phi[j] -= phi[j] / i;
    return phi;
}

template <class T>
vector<T> DivisorSumPHI(T _n){
    vector<T> phi(_n + 1);
    phi[0] = 0, phi[1] = 1;
    for(T i = 2; i <= _n; i++) phi[i] = i - 1;
    for(T i = 2; i <= _n; i++)
        for(T j = 2 * i; j <= _n; j += i)
            phi[j] -= phi[i];
    return phi;
}
