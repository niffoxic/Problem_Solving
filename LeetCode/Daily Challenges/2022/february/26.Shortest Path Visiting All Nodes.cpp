class Solution {
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = graph.size(), res = 0;
        queue<tuple<int, int, int>> q;
        vector<vector<int>> visited(n, vector<int>(1 << n));
        for (int i = 0; i < n; i++) {
            q.push(tuple<int, int, int>(i, 1 << i, 0));
            visited[i][1 << i] = true;
        }
        while (!q.empty()) {
            auto[index, mask, dist] = q.front();
            q.pop();
            if (mask == (1 << n) - 1) {
                res = dist;
                break;
            }
            for (auto v:graph[index]) {
                int vertex_mask = mask | 1 << v;
                if (!visited[v][vertex_mask]) {
                    q.push(tuple<int, int, int>(v, vertex_mask, dist + 1));
                    visited[v][vertex_mask] = true;
                }
            }
        }
        return res;
    }
};
