template <class T>
vector<T> SievePrimeCheck(T _till_){
    vector<T> _primes(_till_ + 1, 1);
    _primes[0] = 0, _primes[1] = 0;
    for(T i = 2; i <= _till_; i++){
        if (_primes[i])
            for(T j = i * 2; j <= _till_; j += i)
                _primes[j] = 0;
    }
    return _primes;
}

template <class T>
vector<T> SievePrimeFactors(T _till_){
    vector<T> _primeFactors;
    for(T i = 0; i <= _till_; i++) _primeFactors.push_back(i);
    for(T i = 2; i <= _till_; i++)
        if (_primeFactors[i] == i)
            for(T j = i * 2; j <= _till_; j += i)
                _primeFactors[j] = i;
    return _primeFactors;
}
