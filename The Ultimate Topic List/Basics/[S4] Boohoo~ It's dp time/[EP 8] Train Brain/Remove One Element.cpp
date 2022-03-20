#include <bits/stdc++.h>
using namespace std;

#define template_size 200005
int arr[template_size];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(2, 1));
    for(int i = 1; i < n; i++){
        if (arr[i - 1] < arr[i]){
            for(int j = 0; j < 2; j++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
        }
        if (i > 1 && arr[i - 2] < arr[i])
            dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
    }
    int res = INT_MIN;
    for(int i = 0; i < n; i++) for(int j = 0; j < 2; j++) res = max(res, dp[i][j]);
    return cout << res, 0;
}
