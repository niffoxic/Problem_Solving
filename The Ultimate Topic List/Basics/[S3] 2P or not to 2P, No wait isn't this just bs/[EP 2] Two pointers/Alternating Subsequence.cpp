#include <bits/stdc++.h>
using namespace std;


int d(int x){
    return x > 0? 1: -1;
}


int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        long long res = 0;
        int index = 0;
        for(; index < n; index++){
            int j = index;
            int current = arr[index];
            while (j < n && d(arr[index]) == d(arr[j])){
                current = max(current, arr[j]);
                j++;
            }
            res += current;
            index = j - 1;
        }
        cout << res << "\n";
    }
    return 0;
}
