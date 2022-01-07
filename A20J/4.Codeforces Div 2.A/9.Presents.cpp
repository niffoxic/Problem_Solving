#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n;i++){
        int p; cin >> p;
        arr[p - 1] = i + 1;
    }
    for(auto i: arr)
        cout << i << " ";
}
