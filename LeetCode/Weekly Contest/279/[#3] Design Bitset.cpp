#include <bits/stdc++.h>

using namespace std;


class Bitset {
public:
    string bits[2];
    int n, ones;
    int i;
    explicit Bitset(int size) {
        ones = 0;
        n = size;
        string x(size, '0');
        string y(size, '1');
        bits[0] = x;
        bits[1] = y;
        i = 0;
    }
    void fix(int idx) {
        if (bits[i][idx] == '1') ones--;
        ones++;
        bits[i][idx] = '1';
        bits[!i][idx] = '0';
    }
    void unfix(int idx) {
        if (bits[i][idx] == '0') ones++;
        ones--;
        bits[i][idx] = '0';
        bits[!i][idx] = '1';
    }
    void flip() {
        i = (i + 1) & 1;
        ones = n - ones;
    }
    [[nodiscard]] bool all() const {
        return ones == n;
    }
    [[nodiscard]] bool one() const {
        return ones > 0;
    }
    [[nodiscard]] int count() const {
        return ones;
    }
    string toString() {
        return bits[i];
    }
};
