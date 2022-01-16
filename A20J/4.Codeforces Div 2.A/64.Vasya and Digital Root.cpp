#include <bits/stdc++.h>
using namespace std;


int main(){
    int k, d; cin >> k >> d;
    if (d > 0){
        cout << d;
        for(int i = 0; i < k - 1; i++)
            cout << 0;
    }else if (k == 1 && !d) cout << 0;
    else cout << "No solution";
    return 0;
}
