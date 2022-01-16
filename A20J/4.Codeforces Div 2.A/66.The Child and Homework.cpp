#include <bits/stdc++.h>
using namespace std;




int main() {
  int a[4];
  string s[4];
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
        a[i] = s[i].size() - 2;
    }
    vector<char> vec;
    for (int i = 0; i < 4; i++) {
        bool check1 = true, check2 = true;
        for (int j = 0; j < 4; j++)
            if (i != j) {
                check1 &= (a[i] >= 2 * a[j]);
                check2 &= (a[j] >= 2 * a[i]);
            }
        if (check1 || check2)
            vec.push_back('A' + i);
    }
    return cout << (vec.size() > 1? 'C': vec[0]), 0;
}
