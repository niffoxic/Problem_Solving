#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    char c;
    cin >> a >> c >> b;
    do {
        b++;
        a += b / 60;
        b %= 60;
        a %= 24;
    } while (a % 10 != b / 10 || a / 10 != b % 10);
    cout << a / 10 << a % 10 << ':' << b / 10 << b % 10;
    return 0;
}
