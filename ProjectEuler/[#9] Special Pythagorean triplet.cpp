#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main() {
    for(ull i = 1; i < 1000; i++){
        for(ull j = i + 1; j < 1000; j++){
            ull c = 1000 - i - j;
            if (j < c && i * i + j * j == c * c){
                cout << i * j * c; break;
            }
        }
    }
    return 0;
}
