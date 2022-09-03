#include <bits/stdc++.h>
using namespace std;


using ll = long long;


int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll arr[n], brr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 0; i < n; i++) cin >> brr[i];
        ll a = 0, b = 0, steps = 0;
        for(int i = 0; i < n; i++){
            if (arr[i] > brr[i]){
                int req = arr[i] - brr[i];
                if (b + brr[i] > arr[i]) b -= req;
                else steps = steps + (req - b), a += (req - b), b = 0;
            }else if (arr[i] < brr[i]){
                int req = brr[i] - arr[i];
                if (a + arr[i] > brr[i]) a -= req;
                else steps = steps + (req - a), b += (req - a), a = 0;
            }
        }
        cout << ((a == b)? steps: -1) << "\n";
    }
    return 0;
}