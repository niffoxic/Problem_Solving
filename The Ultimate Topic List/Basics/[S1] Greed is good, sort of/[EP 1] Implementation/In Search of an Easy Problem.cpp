#include <bits/stdc++.h>

int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n, res = 0; cin >> n;
        int arr[n]; for(int i = 0; i < n; i++){
            int curr; cin >> curr; res += curr;
        }
        print((res?"HARD":"EASY"))
 
 
    }
    return 0;
}
