#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, mini = INT_MAX; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++){
        cin >> arr[i];
        if (mini == INT_MAX)
            mini = arr[i];
        mini = min(mini, arr[i]);
    }
    while (true){
        int local_mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if (mini == arr[i]) continue;
            else{
                if (arr[i] % mini == 0) arr[i] = mini;
                else arr[i] = arr[i] % mini;
            }
            local_mini = min(local_mini, arr[i]);
        }
        if (local_mini == mini || local_mini == INT_MAX)
            break;
        else mini = local_mini;
    }
    int res = 0;
    for(auto i: arr) res += i;
    return cout << res, 0;
}
