#include <bits/stdc++.h>
using namespace std;

#define template_size 100000000

bool primes[template_size];


int main() {
    memset(primes, true, sizeof primes);
    int counts = 0;
    for(int i = 2; i < template_size; i++){
        if (primes[i]){
            counts++;
            if (counts >= 10001){
                cout << i; break;
            }
            for(int j = 2 * i; j < template_size; j += i)
                primes[j] = false;
        }
    }
    return 0;
}
