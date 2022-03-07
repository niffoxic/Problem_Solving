#include <bits/stdc++.h>

using namespace std;

#define template_size 2000001

bool primes[template_size];

void sieve(){
    memset(primes, true, sizeof primes);
    for(int i = 2; i < template_size; i++){
        if (primes[i]) for(int j = 2 * i; j < template_size; j += i) primes[j] = false;
    }
}

using ull = unsigned long long;

int main() {
    sieve();
    ull res = 0;
    for(int i = 2; i < template_size; i++) if (primes[i]) res += i;
    cout << res;
    return 0;
}
