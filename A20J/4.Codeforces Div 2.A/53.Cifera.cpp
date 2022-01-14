#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, l, res{0}; cin >> k >> l;
    while (l != 1 && !(l % k))
        l /= k, res++;
    if (l == 1)
        cout << "YES\n" << res - 1;
    else cout << "NO";
    return 0;
}
