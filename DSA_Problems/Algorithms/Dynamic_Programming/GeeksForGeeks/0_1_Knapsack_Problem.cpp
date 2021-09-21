// Knap Sack recursive solution ( top bottom DP )

int ddp[1001][1001];

int knapSackSolve(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0) return 0;
    if (ddp[W][n] != -1) return ddp[W][n];
    if (wt[n - 1] > W) return knapSackSolve(W, wt, val, n - 1);
    else
        return ddp[W][n] = max(val[n - 1] + knapSackSolve(W - wt[n - 1], wt, val, n - 1), knapSackSolve(W, wt, val, n - 1));
}
// ---------------------------- bottom UP DP -------------------------------------
int knapSack(int weight, int wtr[], int val[], int n) {
    for (int i = 0; i <= 1000; i++) ddp[0][i] = 0;
    for (int i = 0; i <= 1000; i++) ddp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= weight; j++) {
            if (j < wtr[i - 1]) ddp[i][j] = ddp[i - 1][j];
            else {
                ddp[i][j] = max(val[i - 1] + ddp[i - 1][j - wtr[i - 1]], ddp[i - 1][j]);
            }
        }
    }

    return ddp[n][weight];
}
