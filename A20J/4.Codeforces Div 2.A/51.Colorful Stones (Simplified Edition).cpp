#include<bits/stdc++.h>
using namespace std;


int main() {
    string s, t; cin >> s >> t;
    int i = 0, j = 0, n = s.length(), m = t.length();
    while (j < m && i < n){
        if (s[i] == t[j])
            i++;
        j++;
    }
    return cout << i + 1, 0;
}
