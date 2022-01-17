#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static inline int bfs(vector<vector<int>> &g, vector<int> &visited, int id) {
        queue<int> q;

        int level = 0;
        q.push(id);
        while (!q.empty()) {
            int n = q.size();
            level++;
            while (n--) {
                int j = q.front();
                q.pop();
                visited[j] = 1;
                for (auto k: g[j])
                    if (visited[k] == 0) q.push(k);
            }
        }
        return level;
    }


    int maximumInvitations(vector<int> &favorite) {
        int n = favorite.size(), ans_cycle = 0, ans_linear = 0;

        vector<vector<int>> g(n);
        for (int i = 0; i != n; i++) g[favorite[i]].push_back(i);

        vector<int> vis(n, 0);
        for (int i = 0; i != n; i++)
            if (vis[i] == 0)
                for (int next = i, len = 0;; len++)
                    if (vis[next] == 0) {
                        vis[next] = 1;
                        next = favorite[next];
                    } else {
                        int stop = next;
                        next = i;
                        while (next != stop) {
                            vis[next] = 0;
                            next = favorite[next];
                            len--;
                        }

                        if (len == 2) ans_linear += bfs(g, vis, stop) + bfs(g, vis, favorite[stop]);
                        else {
                            ans_cycle = max(ans_cycle, len);

                            queue<int> q;
                            do {
                                q.push(next);
                                next = favorite[next];
                            }
                            while (next != stop);
                            while (!q.empty()) {
                                int j = q.front();
                                q.pop();
                                vis[j] = 1;
                                for (auto k: g[j])
                                    if (vis[k] == 0) q.push(k);
                            }
                        }
                        break;
                    }

        return max(ans_cycle, ans_linear);
    }
};
