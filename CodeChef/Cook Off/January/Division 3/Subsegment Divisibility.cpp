#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int even = 0, odd = 1;
        // 2 1 4 3 6 5
        for(int i = 1; i <= n; i++)
        {
            if (i % 2)
            {
                cout << odd * 2<< " "; odd++;
            }else{
                cout << even * 2 + 1 << " "; even++;
            }
        }
        cout << "\n";
    }
    return 0;
}

