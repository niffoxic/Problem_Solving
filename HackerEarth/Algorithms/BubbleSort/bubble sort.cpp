#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    int res = 0;
    for(int i = 0; i < n; i++){
        bool nope = true;
        res++;
        for(int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]), nope = false;
        if (nope) break;
    }
    return cout << res, 0;
}
