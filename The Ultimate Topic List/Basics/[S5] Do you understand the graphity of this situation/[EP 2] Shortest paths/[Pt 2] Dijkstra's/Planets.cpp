#include <bits/stdc++.h>
using namespace std;

#define INF 10000000000LL
#define template_size 100010
vector<pair<int, int>> graph[template_size];
long long dist[template_size];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
map<int, int> traffic[template_size];


void dijkstra(int source) {
    dist[source] = 0;
    pq.push({source, 0});
    while (!pq.empty()) {
        int topNode = pq.top().first;
        long long d = pq.top().second;
        pq.pop();
        while (traffic[topNode][d] == 1)
            d++;
        for (auto & i : graph[topNode]) {
            if (d + i.second < dist[i.first]) {
                dist[i.first] = d + i.second;
                pq.push({i.first, d + i.second});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    for (int i = 0, x, y, t; i < m; i++)
        cin >>  x >> y >> t, graph[x].emplace_back(y, t), graph[y].emplace_back(x, t);
    for (int i = 1, ts; i <= n; i++) {
        cin >> ts;
        for (int j = 0, t; j < ts; j++) cin >> t, traffic[i][t] = 1;
    }
    dijkstra(1);
    return cout << (dist[n] == INF? -1: dist[n]), 0;
}
