#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while (t--){
        double x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << (x1 / y1 == x2 / y2? 0: x1 / y1 > x2 / y2? -1: 1) << "\n" ;
    }
    return 0;
}
