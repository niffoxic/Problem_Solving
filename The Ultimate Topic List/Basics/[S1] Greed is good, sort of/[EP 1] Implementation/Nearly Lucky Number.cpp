#include <bits/stdc++.h>


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        string n; cin >> n;
        int res = 0;
        for(auto i: n){
            if (i == '7' || i == '4') res++;
        }
        int ans[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
        bool fn = false;
        for(int an : ans) if (res == an) fn = true;
        cout<<(fn?"YES": "NO") << "\n";
    }
    return 0;
}
 
 
 
 
 
 
 
