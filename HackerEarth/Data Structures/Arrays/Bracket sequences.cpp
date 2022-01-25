#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int balanced = 0, mini = INT_MAX, c = 0;
    for(char i : s){
        if (i == '(') balanced++;
        else balanced--;
        if (mini > balanced) mini = balanced, c = 0;
        if (balanced == mini) c++;
    }
    return cout << (balanced? 0: c), 0;
}
