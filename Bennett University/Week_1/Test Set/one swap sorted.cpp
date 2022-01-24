#include <bits/stdc++.h>
using namespace std;



void solve(int case_no)
{
    int n; cin >> n;
    string s, t; cin >> s;
    t = s; sort(t.begin(), t.end());
    int res = 0;
    for(int i = 0; i < n; i++) if (s[i] != t[i]) res++;
    cout << (res <= 2? "YES":"NO") << "\n";
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
