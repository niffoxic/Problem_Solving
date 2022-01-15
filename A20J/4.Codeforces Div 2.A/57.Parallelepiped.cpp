#include <bits/stdc++.h>
using namespace std;


int main(){
    int ax, bx, cx, a, b, c; cin >> ax >> bx >> cx;
    a = sqrt((ax * cx) / bx);
    b = sqrt((ax * bx) / cx);
    c = sqrt((bx * cx) / ax);
    return cout << 4 * (a + b + c), 0;
}
