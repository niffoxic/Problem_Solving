#include <bits/stdc++.h>
using namespace std;


void solve(int case_no){
    int s, x, n; cin >> s >> x >> n;
    vector<pair<int, int>> others;
    for(int i = 0, t, y; i < n; i++) cin >> t >> y, others.emplace_back(t, y);
    sort(others.begin(), others.end());
    int days = 0, covered = 0, index = 0;
    while (covered < s && index < n){
        int days_needed = ((s - covered) / x) + ((s - covered) % x != 0);
        // cout << "days needed if we use normal x: " << days_needed << "\n";
        int intervals = others[index].first - days - 1;
        // cout << "Days we have to allot normal x: " << intervals << "\n";

        // when we have enough normal days than needed
        if (days_needed <= intervals) days += days_needed, covered += days_needed * x;
        else{
            // when we don't have enough normal days to cover distance.
            days += intervals + 1;
            covered = covered + intervals * x + others[index].second;
        }
        index++;
    }
    if (covered < s) days += ((s - covered) / x) + (((s - covered) % x) != 0);
    cout << days << "\n";
}


int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
}
