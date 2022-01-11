#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, mini = INT_MAX, maxi = INT_MIN; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++){
        cin >> arr[i];
        if (i > 1)
            mini = min(mini, arr[i] - arr[i - 2]);
        if (i > 0)
            maxi = max(maxi, arr[i] - arr[i - 1]);
    }
    cout << max(mini, maxi);
    return 0;
}
