#include<bits/stdc++.h>
using namespace std;


int main() {
    int arr[2], c = 0, w = 0; cin >> arr[0] >> arr[1];
    int mini[2]{100, 100}, maxi[2]{0, 0};

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < arr[i]; j++){
            int t; cin >> t;
            mini[i] = min(mini[i], t);
            maxi[i] = max(maxi[i], t);
        }
    }
    int res = maxi[0] < mini[1] && maxi[0] >= mini[0] * 2? maxi[0]:
            mini[0] * 2 < mini[1] && mini[1] > maxi[0]? mini[0] * 2:
            -1;
    return cout << res, 0;
}
