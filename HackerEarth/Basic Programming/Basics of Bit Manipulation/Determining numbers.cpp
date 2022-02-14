#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    int res = 0;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (n == 2) {
        cout << min(arr[0], arr[1]) << " " << max(arr[1], arr[0]) << endl;
    } else {
        for (int i = 0; i < n; i++) res = res ^ arr[i];
        int i = 0;
        int temp = res;
        while (temp > 0) {
            if (temp & 1) break;
            i++;
            temp = temp >> 1;
        }

        int mask = (1 << i);

        int first = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & arr[i])) {
                first = first ^ arr[i];
            }
        }
        cout << min(first, (first ^ res)) << " " << max((first ^ res), first) << endl;
    }
    return 0;
}
