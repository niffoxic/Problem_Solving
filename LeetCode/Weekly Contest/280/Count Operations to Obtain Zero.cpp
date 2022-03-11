#include <bits/stdc++.h>
using namespace std;

int countOperations(int num1, int num2) {
    int mx, mn, res = 0;
    while (num1 and num2) {
        if (num1 > num2) mx = num1, mn = num2, num1 %= num2;
        else mx = num2, mn = num1, num2 %= num1;
        res += mx / mn;
    }
    return res;
}
