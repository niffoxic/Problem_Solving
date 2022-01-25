#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int res = 1;
    for(int i = 1; i < n; i++) if (arr[i] != arr[i - 1]) res++;
    return cout << res, 0;
}
