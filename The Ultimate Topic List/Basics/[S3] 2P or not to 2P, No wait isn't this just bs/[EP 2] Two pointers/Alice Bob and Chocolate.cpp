#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    int left = -1, right = n, alice = 0, bob = 0, c1 = 0, c2 = 0;
    while (left < right){
        if (alice > bob){
            right--;
            if (left != right) bob += arr[right], c2++;
        }else{
            left++;
            if (left != right) alice += arr[left], c1++;
        }
    }
    cout << c1 << " " << c2;
    return 0;
}
