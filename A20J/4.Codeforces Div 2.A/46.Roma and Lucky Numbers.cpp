#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    int luck, res = 0;
    while (n--){
        string s; cin >> s;
        luck = 0;
        for(auto i: s)
            if (i == '4' || i == '7')
                luck++;
        if (luck <= k)
            res++;
    }
    cout << res;
    return 0;
}
