#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin >> n;
    set<char> diag, rest;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            char x; cin >> x;
            if(i == j || i == n - j - 1)
                diag.insert(x);
            else
                rest.insert(x);
        }
    }
    if(diag.size() == 1 && rest.size() == 1 && *diag.begin() != *rest.begin())
        return cout << "YES", 0;
    return cout << "NO", 0;
}
