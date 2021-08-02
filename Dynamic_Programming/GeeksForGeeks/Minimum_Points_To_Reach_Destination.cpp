	int minPoints(vector<vector<int>> points, int M, int N)
{
    int r = points.size();
    int c = points[0].size();
    int dp[r + 1][c + 1];
    for(int i = 0; i <= r; i++) for(int j = 0; j <= c; j++) dp[i][j] = 0;

    for(int i = r - 1; i >= 0; i--){
        for(int j = c - 1; j >= 0; j--){
            if (i == r - 1 && j == c - 1)
                dp[i][j] = min(0, points[i][j]);
            else if (i == r - 1)
                dp[i][j] = min(0, points[i][j] + dp[i][j + 1]);
            else if (j == c - 1)
                dp[i][j] = min(0, points[i][j] + dp[i + 1][j]);
            else dp[i][j] = min(0, points[i][j] + max(dp[i][j + 1], dp[i + 1][j]));
        }
    }
    return abs(dp[0][0]) + 1;
}
