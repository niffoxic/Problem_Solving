#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k, keySize = 0; cin >> n;
    int feq[n]; for(int i = 0; i < n; i++) cin >> feq[i];
    cin >> k; int keyPad[k]; for(int i = 0; i < k; i++){
        cin >> keyPad[i];
        keySize += keyPad[i];
    }
    if (n > keySize)
        return cout << -1, 0;
    sort(feq, feq + n, greater<>());
    sort(keyPad, keyPad + k, greater<>());
    int res = 0;
    int i = 0, allotted = 1;
    while (i < n)
    {
        for(int j = 0; j < k; j++)
        {
            if (i == n) break;
            if (keyPad[j]){
                keyPad[j]--;
                res += feq[i++] * allotted;
                continue;
            }
            break;
        }
        allotted++;
    }
    return cout << res, 0;
}
