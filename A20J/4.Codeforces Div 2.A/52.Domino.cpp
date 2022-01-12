#include<bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    int left = 0, right = 0;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        left += a[i], right += b[i];
    }
    if (!(left % 2) && !(right % 2))
        cout << 0;
    else{
        int res = -1;
        for(int i = 0; i < n && res == -1; i++)
            if ((left - a[i] + b[i]) % 2 == 0
            && (right + a[i] - b[i]) % 2 == 0)
                res = 1;
        cout << res;
    }
    return 0;
}
