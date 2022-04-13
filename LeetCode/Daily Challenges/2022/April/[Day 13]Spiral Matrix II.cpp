
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r1 = 0, r2 = n-1, c1 = 0, c2 = n-1, val = 0;
        vector<vector<int>> res(n, vector<int> (n));
        while(r1 <= r2 && c1 <= c2)
        {
            for(int i = c1; i <= c2; ++i) res[r1][i] = ++val;
            for(int i = r1+1; i <= r2; ++i) res[i][c2] = ++val;
            if(r1 < r2 && c1 < c2)
            {
                for(int i = c2-1; i>c1; --i) res[r2][i] = ++val;
                for(int i = r2; i>r1; --i) res[i][c1] = ++val;
            }
            ++r1, --r2, ++c1, --c2;
        }
        return res;
    }
};
