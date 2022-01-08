#include<bits/stdc++.h>
using namespace std;


int main()
{
    int arr[26] = {0};
    string s;
    while (cin >> s)
        for(auto i: s)
            if (i - 'a' >= 0 && i - 'a' < 26)
                arr[i - 'a'] = 1;
    int res = 0;
    for(auto i: arr)
        res += i;
    cout << res;
    return 0;
}
