// Top to bottom DP;
int dp3[101][101];
int solve_ed(str s1, int n1, str s2, int n2){
    if (n1 == 0) return n2; if (n2 == 0) return n1;
    if (dp3[n1][n2] != -1) return dp3[n1][n2];

    if (s1[n1 - 1] == s2[n2 - 1]) return solve_ed(s1, n1 - 1, s2, n2 - 1);
    return dp3[n1][n2] = 1 + min(solve_ed(s1, n1 - 1, s2, n2), min(solve_ed(s1, n1, s2, n2 - 1), solve_ed(s1, n1 - 1, s2, n2 - 1)));
}

int edit_distance(str s1, str s2){
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            dp3[i][j] = -1;
        }
    }
    return solve_ed(s1, s1.size(), s2, s2.size());
}
