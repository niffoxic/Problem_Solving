// PKANFPOKAGNFPOASWMNPOSWVGNPOWSDMGNDPDOMFBPODBMNPOBNFPODBNFPOAMNPVOSM POAVNFAOKVNAP DAMKNNNNNNNNNNNN! THIS QUESTION

int dp[201][201][2];

int solve(string &s1, int i, int j, bool condition){
    if (i > j) return dp[i][j][condition] = 0;

    if (i == j){
        if (condition) return s1[i] == 'T';
        else return s1[i] == 'F';
    }
    if (dp[i][j][condition]  != -1) return dp[i][j][condition];
    
    int res = 0;

    for(int k = i + 1; k < j; k += 2){

        int left_true = dp[i][j - 1][1] == -1 ? solve(s1, i, k - 1, true):  dp[i][j - 1][1];
        int left_false = dp[i][j - 1][0] == -1 ? solve(s1, i, k - 1, false):  dp[i][j - 1][0];
        int right_true = dp[i + 1][j][1] == -1 ? solve(s1, k + 1, j, true):  dp[i + 1][j][1];
        int right_false = dp[i + 1][j][0] == -1 ? solve(s1, k + 1, j, false):  dp[i + 1][j][0];



        if (s1[k] == '&'){
            if (condition) res += left_true * right_true;
            else res += left_true * right_false + left_false * right_true + left_false * right_false;

        }

        if (s1[k] == '|'){

            if (condition) res += left_true * right_false + left_false * right_true + left_true * right_true;
            else res += right_false * left_false;

        }

        if (s1[k] == '^'){

            if (condition) res += left_false * right_true + left_true * right_false;
            else res += left_true * right_true + left_false * right_false;

        }
    }

    return dp[i][j][condition]  = res % 1003;
}

int countWays(int n, string s1){
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) for(int k = 0; k < 2; k++) dp[i][j][k] = -1;
    return solve(s1, 0, n - 1, true);
}
