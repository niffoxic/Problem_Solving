#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr[3];
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        arr[t - 1].push_back(i + 1);
    }
    int w = min(arr[0].size(), min(arr[1].size(), arr[2].size()));
    cout << w << "\n";
    for(int i = 0; i < w; i++){
        cout << arr[0][i] << " " << arr[1][i] << " " << arr[2][i] << "\n";
    }
    return 0;
}
