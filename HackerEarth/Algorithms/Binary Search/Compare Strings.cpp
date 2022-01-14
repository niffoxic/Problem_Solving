#include <bits/stdc++.h>
using namespace std;

using str = string;


int main()
{
    int n, q; cin >> n >> q;
    int ac = 0, bc = 0;
    str s1, s2; cin >> s1 >> s2;
    for(int i = 0; i < n; i++){
        if (s1[i] == '1') ac++;
        if (s2[i] == '1') bc++;
    }
    for(int i = 0; i < q; i++)
    {
        int k; cin >> k;
        if (s2[k - 1] != '1'){
            s2[k - 1] = '1';
            bc++;
        }
        cout << (bc == ac?"YES":"NO") << "\n";
    }
    return 0;
}
