#include<bits/stdc++.h>

using namespace std;

int main() {
    char c;
    string s, s1, s2 = "6789TJQKA";
    cin >> c >> s >> s1;
    cout << (((s[1] == s1[1] && s2.find(s[0]) > s2.find(s1[0])) || (s[1] == c && s1[1] != c)) ? "YES" : "NO");
    return 0;
}
