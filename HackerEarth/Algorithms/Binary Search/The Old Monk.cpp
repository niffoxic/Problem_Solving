#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve(int case_no){
    int n; cin >> n;
    ll arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    ll brr[n]; for(int i = 0; i < n; i++) cin >> brr[i];
    ll res = INT_MIN;
    for(int j = 0; j < n; j++){
        ll bj = brr[j];
        ll left = 0, right = j, mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if (arr[mid] > bj)
                left = mid + 1;
            else if (arr[mid] < bj)
                right = mid - 1;
            else{
                if (mid == 0 || arr[mid] != arr[mid - 1]) break;
                else
                    right = mid - 1;
            }
        }
        ll temp;
        if (arr[mid] > bj){
            mid = mid + 1;
            if (mid > j) temp = 0;
            else
                temp = j - mid;

        }else temp = j - mid;
        res = max(res, temp);
    }
    cout << res << "\n";
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
