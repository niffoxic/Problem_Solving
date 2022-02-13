#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        if (k == 1){
            cout << "YES\n";
            for(int i = 1; i <= n; i++) cout << i << "\n";
        }else if (n % 2){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            for(int i = 1; i <= n; i++){
                for(int j = i; j <= n * k; j += n)
                    cout << j << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}
