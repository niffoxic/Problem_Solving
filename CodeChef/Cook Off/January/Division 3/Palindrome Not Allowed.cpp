#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s;
        for(int j = 0; j < n; j++){
            s += 'a' + (j % 26);
        }
        cout << s << "\n";
    }
    return 0;
}

