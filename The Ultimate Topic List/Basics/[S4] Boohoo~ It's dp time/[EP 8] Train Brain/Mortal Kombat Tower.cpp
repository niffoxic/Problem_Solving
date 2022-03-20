#include <bits/stdc++.h>
using namespace std;

#define template_size 200005
int arr[template_size], dp[template_size][3], n;

int recursion(int i, int turn){
    if (i >= n) return 0;
    if (dp[i][turn] != -1) return dp[i][turn];
    int res;
    if (turn == 2) res = min(recursion(i + 1, 1), recursion(i + 2, 1));
    else{
        int k1 = arr[i] == 1, k2 = (arr[i] == 1) + (arr[i + 1] == 1);
        res = min(k1 + recursion(i + 1, 2), k2 + recursion(i + 2, 2));
    }
    return dp[i][turn] = res;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i <= n; i++) for(int j = 0; j < 3; j++) dp[i][j] = -1;
    cout << recursion(0, 1) << "\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
