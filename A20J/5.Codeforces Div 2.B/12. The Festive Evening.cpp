#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    unordered_map<char, int> opens;
    unordered_map<char, int> closed;
    for(int i = 0; i < n; i++){
        if (opens.find(s[i]) == opens.end()) opens[s[i]] = i;
        if (closed.find(s[i]) == closed.end()) closed[s[i]] = i;
        opens[s[i]] = min(opens[s[i]], i),closed[s[i]] = max(closed[s[i]], i);
    }
    int guards = 0, res = 1;
    for(int i = 0; i < n && res; i++){
        if (opens[s[i]] == i) guards++;
        if (guards > k) res = 0;
        if (closed[s[i]] == i) guards--;
    }
    cout << (res? "NO": "YES");
    return 0;
}
