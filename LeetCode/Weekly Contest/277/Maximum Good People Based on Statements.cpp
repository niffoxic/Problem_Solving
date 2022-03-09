class Solution {
public:
    int n;
    int valid(int val, vector<vector<int>> &statements, int mask) {
        if (val == n) {
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i))) {
                    for (int j = 0; j < n; j++) {
                        int val = (mask & (1 << j)) ? 1 : 0;
                        if (statements[i][j] != 2 && statements[i][j] != val) return INT_MIN;
                    }
                }
            }
            return 0;
        }
        int a = valid(val + 1, statements, mask);
        int b = 1 + valid(val + 1, statements, (mask | (1 << val)));
        return max(a, b);
    }

    int maximumGood(vector<vector<int>> &statements) {
        n = statements.size();
        int res = valid(0, statements, 0);
        return res < 0 ? 0 : res;
    }
};
