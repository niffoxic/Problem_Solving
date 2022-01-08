#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, p; cin >> n;
    vector<int> l(n, 0);

    for(int i = 0; i < 2; i++){
        cin >> p;
        for(int j = 0; j < p; j++){
            int k; cin >> k;
            l[k - 1]++;
        }
    }
    int res = 1;
    for(int i = 0; i < n && res; i++)
        if (!l[i])
            res = 0;
    cout << ((res)?"I become the guy.": "Oh, my keyboard!");
    return 0;
}
