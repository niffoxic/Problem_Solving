#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    bool side = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if (i % 2)
                cout << "#";
            else
            {
                if ((side && j == m - 1) || (!side && j == 0))
                    cout << "#";
                else
                    cout << ".";
            }
        }
        if (!(i % 2))
            side = !(side);
        cout << "\n";
    }
    return 0;
}
