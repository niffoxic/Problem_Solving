#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    int arr[201][2];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> arr[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x = arr[i][0], y = arr[i][1];
        int left = 0, right = 0, up = 0, below = 0;
        for (int j = 0; j < n; j++) {
            if (x < arr[j][0] && y == arr[j][1]) {
                right++;
            } else if (x > arr[j][0] && y == arr[j][1]) {
                left++;
            } else if (x == arr[j][0] && y < arr[j][1]) {
                up++;
            } else if (x == arr[j][0] && y > arr[j][1]) {
                below++;
            }
            if (right > 0 && left > 0 && up > 0 && below > 0) {
                if ((left + right + up + below) >= 4) {
                    res++;
                    break;
                }
            }
        }
    }
    cout << res;
    return 0;
}
