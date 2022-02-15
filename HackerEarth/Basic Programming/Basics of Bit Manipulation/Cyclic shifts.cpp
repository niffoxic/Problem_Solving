#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, p; char c; cin >> n >> p >> c;
        vector<int> arr(16, 0);
        for(int i = 0; i < 16; i++)
            if (n & (1 << i)) arr[i] = 1;
        p %= 16;
        if (c == 'L'){
            reverse(arr.begin(), arr.end());
            reverse(arr.begin(), arr.begin() + p);
            reverse(arr.begin() + p, arr.end());
        }else{
            reverse(arr.begin(), arr.begin() + p);
            reverse(arr.begin() + p, arr.end());
            reverse(arr.begin(), arr.end());
        }
        int res = 0;
        for(int i = 0; i < 16; i++) if (arr[i]) res += 1 << i;
        cout << res << "\n";
    }
    return 0;
}
