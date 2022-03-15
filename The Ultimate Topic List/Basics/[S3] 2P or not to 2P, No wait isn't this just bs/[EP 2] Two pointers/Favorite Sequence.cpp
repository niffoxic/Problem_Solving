#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        int left = 0, right = n - 1;
        while (left <= right){
            cout << arr[left] << " ";
            if (left != right)
                cout << arr[right] << " ";
            left++, right--;
        }
        cout << "\n";
    }
    return 0;
}
