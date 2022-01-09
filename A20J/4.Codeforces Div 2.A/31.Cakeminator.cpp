#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    char p[11][11];
    cin >> n >> m;
    set<int> x, y;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> p[i][j];
            if (p[i][j] == 'S'){
                x.insert(i), y.insert(j);
            }
        }
    }
    cout << m * n - x.size() * y.size();
    return 0;
}
