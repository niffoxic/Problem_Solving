#include <bits/stdc++.h>

using namespace std;
#define template_size 1000005

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int t, n, m, Lx, Ly;
string s[template_size];

bool valid(int u, int v) {
    return u >= 0 && u < n && v >= 0 && v < m && s[u][v] == '.';
}

int getDirections(int x, int y) {
    int ways = 0;
    for(int i = 0; i < 4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if (valid(u, v)) ways++;
    }
    return ways;
}

void dfs(int x, int y) {
    if (s[x][y] != 'L') s[x][y] = '+';
    for (int i = 0; i < 4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if (valid(u, v) && getDirections(u, v) <= 1) dfs(u, v);
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            for(int j = 0; j < m; j++) if (s[i][j] == 'L') Lx = i, Ly = j;
        }
        dfs(Lx, Ly);
        for(int i = 0; i < n; i++) cout << s[i] << '\n';
    }
}
