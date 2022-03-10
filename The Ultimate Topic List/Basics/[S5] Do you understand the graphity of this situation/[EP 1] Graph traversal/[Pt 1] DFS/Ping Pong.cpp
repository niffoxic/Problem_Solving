#include<bits/stdc++.h>
using namespace std;

#define template_size 105
int n, q, x, y;
bool res;
int visited[template_size];
vector<pair<int, int>> pairs;

void dfs(int v) {
    if (v == y) {
        res = true;
        return;
    }
    visited[v] = 1;
    for (int i = 1; i < pairs.size(); i++)
        if (!visited[i])
            if ((pairs[v].first > pairs[i].first && pairs[v].first < pairs[i].second) ||
                (pairs[v].second > pairs[i].first && pairs[v].second < pairs[i].second))
                dfs(i);
}

int main() {
    pairs.emplace_back(0, 0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q >> x >> y;
        if (q == 1)pairs.emplace_back(x, y);
        if (q == 2) {
            memset(visited, false, sizeof visited);
            res = false;
            dfs(x);
            cout << (res ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
