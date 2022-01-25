#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << arr[0] << " ";
        for(int i = 1; i < n; i++){
            arr[i] = arr[i] * ((arr[i - 1] + arr[i] - 1) / arr[i]);
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
