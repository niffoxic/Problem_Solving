#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        int left = arr[0] == arr[n - 1] && arr[0] == 0, right = arr[0] == arr[n - 1] && arr[0] == 1;
        for(int i = 0; i < n - 1; i++) left += (arr[i] == arr[i + 1] && arr[i] == 0),
        right += (arr[i] == arr[i + 1] && arr[i] == 1);
        cout << ((min(left, right) & 1)? "Alice": "Bob") << "\n";

    }
    return 0;
}