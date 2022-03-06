#include <bits/stdc++.h>
using namespace std;

#define template_size 10002
#define inf 30000

int n, m, v[template_size], u[template_size], w[template_size],
        dis[template_size];

void bellman(){
    memset(dis, 63, sizeof dis);
    dis[1] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= m; j++)
            if (dis[v[j]] < inf && dis[u[j]] > dis[v[j]] + w[j])
                dis[u[j]] = dis[v[j]] + w[j];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> v[i] >> u[i] >> w[i];
    bellman();
    for(int i = 1; i <= n; i++)
        if (dis[i] >= inf) dis[i] = 30000;
    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    return 0;
}
