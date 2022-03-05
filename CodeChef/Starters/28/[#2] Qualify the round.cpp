#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while (t--){
        int x, a, b; cin >> x >> a >> b;
        cout << (x <= a + 2 * b? "Qualify":
        "NotQualify") << "\n";
    }
    return 0;
}
