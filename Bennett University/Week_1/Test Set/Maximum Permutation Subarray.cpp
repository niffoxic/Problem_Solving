#include <bits/stdc++.h>
using namespace std;



void solve(int case_no)
{
    int n; cin >> n;
    int arr[n];
    unordered_set<int> st;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int j = 0; j < n; j++){
        int t; cin >> t; st.insert(t);
    }

    int res[50] = {0};
    for(int i = 0; i < n; i++)
        if (st.find(arr[i]) != st.end())
            res[i] = 1;


    int ans = res[0]? 1: 0;
    int current = ans;
    for(int i = 1; i < 50; i++){
        if (res[i])
            current++;
        else{
            ans = max(ans, current);
            current = 0;
        }
    }
    ans = max(ans, current);
    cout << ans << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int test_case = 1;
    cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
