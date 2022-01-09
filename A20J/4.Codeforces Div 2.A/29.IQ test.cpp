#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    int remind = (arr[0] % 2 == arr[1] % 2)? arr[0] % 2: (arr[0] % 2 == arr[2] % 2)? arr[0] % 2: arr[1] % 2;
    int res = 0;
    for(int i = 0; i < n; i++)
        if (arr[i] % 2 != remind)
        {
            res = i; break;
        }
    cout << res + 1;
    return 0;
}
