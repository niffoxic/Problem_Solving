#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int team = 0, mem = 0;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        if (t + k <= 5)
            mem++;
        if (mem == 3){
            team++; mem = 0;
        }
    }
    cout << team;
    return 0;
}
