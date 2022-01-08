#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long int n, k, res = 0; cin >> n >> k;
    if (n % 2){
        if ((n / 2) + 1 >= k)
            res = (2 * k) - 1;
        else
            k -= ((n / 2) + 1);
    }else{
        if ((n / 2) >= k)
            res = (2 * k) - 1;
        else
            k -= (n / 2);
    }
    if (!res)
        res = k * 2;
    cout << res;
    return 0;
}
