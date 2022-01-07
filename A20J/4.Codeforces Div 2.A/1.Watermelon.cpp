#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    if (n - 2 > 0 && (n - 2) % 2 == 0)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
