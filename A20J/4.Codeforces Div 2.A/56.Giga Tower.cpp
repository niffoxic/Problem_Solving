#include <bits/stdc++.h>
using namespace std;

bool found(int x){
    x = abs(x);
    while (x){
        if (x % 10 == 8)
            return true;
        x /= 10;
    }
    return false;
}

int main(){
    int a, res = 1; cin >> a;
    while (!found(a + res)) res++;
    return cout << res, 0;
}
