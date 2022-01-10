#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int x = k * l, y = x / nl, z = c * d, m = p / np;
    cout << (min(min(y, z), m)) / n;
}
