#include <bits/stdc++.h>
using namespace std;

string colors[51];
bool visited[51][51];
int n, m, res = 0;

int dx[]{1, -1, 0, 0};
int dy[]{0, 0, -1, 1};

void dfs(int r, int c, int pr, int pc){
    if (visited[r][c]){
        res = 1; return;
    }
    visited[r][c] = true;
    for(int i = 0; i < 4; i++){
        int x = r + dx[i], y = c + dy[i];
        if ((x != pr || y != pc) &&
        x >= 0 && x < n && y >= 0 && y < m && colors[r][c] == colors[x][y])
            dfs(x, y, r, c);
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> colors[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) if (!visited[i][j])dfs(i, j, -1, -1);
    return cout << (res? "Yes": "No"), 0;
}
