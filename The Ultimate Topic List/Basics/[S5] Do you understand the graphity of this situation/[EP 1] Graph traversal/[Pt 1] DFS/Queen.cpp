#include <bits/stdc++.h>
using namespace std;



int main(){
    int n; cin >> n;
    bool nodes[n + 1];
    for(int i = 0; i <= n; i++) nodes[i] = false;
    for(int i = 1; i <= n; i++){
        int pi, ci; cin >> pi >> ci;
        if (ci == 0) nodes[i] = true, nodes[pi] = true;
    }

    int res = 0;
    for(int i = 1; i <= n; i++) if (!nodes[i]) cout << i << " ", res++;
    cout << (res? "\n": "-1\n");
    return 0;
}
