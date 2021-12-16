// Maximize the Cut Segments

// Recursion
int maximizeTheCutsSolve(int n, int x, int y, int z) {
    if (n == 0) return 0;
    if (n < 0) return -1;
    
    int left = maximizeTheCutsSolve(n - x, x, y, z);
    int mid = maximizeTheCutsSolve(n - y, x, y, z);
    int right = maximizeTheCutsSolve(n - z, x, y, z);

    int res = max(left, max(mid, right));

    if (res == -1) return res;
    return res + 1;
}

// DP solution
int maximizeTheCuts(int n, int x, int y, int z) {
    int dp6[10001]; dp6[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp6[i] = -1;
   
        if (i - x >= 0) dp6[i] = max(dp6[i], dp6[i - x]);
        if (i - y >= 0) dp6[i] = max(dp6[i], dp6[i - y]);
        if (i - z >= 0) dp6[i] = max(dp6[i], dp6[i - z]);

        if (dp6[i] != -1) dp6[i] += 1;
    }
    return (dp6[n] == -1) ? 0 : dp6[n];
}
