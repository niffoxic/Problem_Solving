#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOrders(int n) {
        int res = 1, mod = 1e9 + 7;
        for(int i = 1; i <= n; i++){
            res = (res * i) % mod;
            res *= (2 * i - 1);
            res %= mod;
        }
        return res % mod;
    }
};

int main(){
    return 0;
}
