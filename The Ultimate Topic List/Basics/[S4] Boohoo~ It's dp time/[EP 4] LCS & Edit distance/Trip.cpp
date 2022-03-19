#include <bits/stdc++.h>
using namespace std;
string s, t;
void printLCS(string& s1, string& s2)
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    vector<vector<unordered_set<string>>> all_(m + 1, vector<unordered_set<string>>(n + 1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++) dp[i][j] = s1[i - 1] == s2[j - 1]? 1 + dp[i - 1][j - 1]: max(dp[i - 1][j], dp[i][j - 1]);
    }
    for(int j = 0; j <= n; j++) all_[0][j].insert("");
    for(int i = 0; i <= m; i++) all_[i][0].insert("");
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1]){
                for(const auto &prev: all_[i - 1][j - 1])
                    all_[i][j].insert(prev + s1[i - 1]);
            }else if(dp[i - 1][j] == dp[i][j - 1]){
                for(const auto &prev: all_[i - 1][j]) all_[i][j].insert(prev);
                for(const auto &prev: all_[i][j - 1]) all_[i][j].insert(prev);
            }else{
                const auto &best = dp[i - 1][j] > dp[i][j - 1]? all_[i - 1][j]: all_[i][j - 1];
                for(const auto &prev: best) all_[i][j].insert(prev);
            }
        }
    }
    vector<string> res(all_[m][n].begin(), all_[m][n].end());
    sort(res.begin(), res.end());
    for(const auto& i: res) cout << i << "\n";
}


void solve() {
    cin >> s >> t;
    printLCS(s, t);
}

int main() {
    int test;
    cin >> test;
    while (test--) solve();
    return 0;
}
