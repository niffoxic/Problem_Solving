#include <bits/stdc++.h>

using namespace std;


int grid[51][51];
int dp[51][51];
int n, m;
int dx[]{1, -1, 0, 0, 1, -1, -1, 1};
int dy[]{0, 0, 1, -1, -1, 1, -1, 1};

bool notValid(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= m;
}

int dfs(int r, int c) {
    if (dp[r][c] != -1) return dp[r][c];
    int current = 1, res = 0;
    for (int i = 0; i < 8; i++) {
        int nx = r + dx[i], ny = c + dy[i];
        if (!notValid(nx, ny) && grid[nx][ny] == grid[r][c] + 1)
            res = max(dfs(nx, ny), res);
    }
    current += res;
    return dp[r][c] = current;
}

void solve(int case_no) {
    memset(dp, -1, sizeof dp);
    vector<pair<int, int>> startPosition;
    startPosition.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            grid[i][j] = (c - 'A');
            if (c == 'A') startPosition.emplace_back(i, j);
        }
    }
    if (startPosition.empty()) cout << "Case " << case_no << ": " <<  0 << "\n";
    else {
        int res = 0;
        for (auto i: startPosition) {
            res = max(res, dfs(i.first, i.second));
        }
        cout << "Case " << case_no << ": " <<  res << "\n";
    }
}

int main() {
    int t = 1;
    while (true){
        cin >> n >> m;
        if (!n && !m) break;
        solve(t); t++;
    }
    return 0;
}
