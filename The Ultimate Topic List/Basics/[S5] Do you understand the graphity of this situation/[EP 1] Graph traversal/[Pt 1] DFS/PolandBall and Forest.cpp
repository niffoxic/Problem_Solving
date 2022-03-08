#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    unordered_set<int> st;
    int res = 0;
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        if (t == i) res++;
        else st.insert(t);
    }
    return cout << res + (st.size() >> 1), 0;
}
