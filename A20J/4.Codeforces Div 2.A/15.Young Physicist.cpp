#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    vector<int>arr(3, 0);
    while(n--)
    {
        int x, y, z; cin >> x >> y >> z;
        arr[0] += x, arr[1] += y, arr[2] += z;
    }
    cout << ((!arr[0] && !arr[1] && !arr[2])? "YES": "NO");
    return 0;
}
