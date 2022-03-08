#include <bits/stdc++.h>
using namespace std;


int main(){
    long long a, b; cin >> a >> b;
    stack<long long> res;
    while (a < b){
        res.push(b);
        if (!(b & 1)) b >>= 1;
        else if (b % 10 == 1) b /= 10;
        else break;
    }
    res.push(a);
    if (a == b){
        cout << "YES\n" << res.size() << "\n";
        long long t;
        while (!res.empty()) t = res.top(), res.pop(), cout << t << " ";
    }else cout << "NO";
    return 0;
}
