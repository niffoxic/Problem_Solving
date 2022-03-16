#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e16;
vector<ll> d;
set<pair<ll, ll>> st;


void bfs(vector<ll> *g, ll src) {
    set<pair<ll, ll>>::iterator it;

    for (int i = 0; i < g[src].size(); i++) {
        ll v = g[src][i];
        if (d[src] + 1 < d[v]) {

            it = st.find({d[v], v});
            st.erase(it);
            d[v] = d[src] + 1;
            st.insert({d[v], v});
        }
    }

    if (st.size() == 0)
        return;

    it = st.begin();
    ll next = it->second;
    st.erase(it);

    bfs(g, next);
}

void bfs(vector<ll> s[], ll n, vector<ll> &s, ll k) {
    vector<ll> source(n + 1, 0);

    for (int i = 0; i < k; i++) source[s[i]] = 1;

    for (int i = 1; i <= n; i++) {
        if (source[i]) {
            d[i] = 0;
            st.insert({0, i});
        } else {
            d[i] = INF;
            st.insert({INF, i});
        }
    }

    auto itr = st.begin();
    ll start = itr->second;

    bfs(s, start);
}

void solve() {
    int n, m, k, u, v, q;
    cin >> n >> m >> k;
    vector<ll> graph[n + 1], sp(k);
    for (int i = 0; i < m; ++i)
        cin >> u >> v, graph[u].push_back(v), graph[v].push_back(u);
    for (int i = 0; i < k; ++i) cin >> sp[i];
    d = vector<ll>(n + 1, INF);
    bfs(graph, n, sp, k);
    cin >> q;
    while (q--) {
        cin >> u;
        cout << (d[u] >= INF ? -1 : d[u]) << endl;
    }

}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
