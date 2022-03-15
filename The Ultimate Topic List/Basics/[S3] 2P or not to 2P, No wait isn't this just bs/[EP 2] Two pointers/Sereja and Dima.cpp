#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int left = 0, right = n - 1;
    int x = 0, y = 0;
    while (left <= right){
        if (arr[left] > arr[right]) x += arr[left], left++;
        else x += arr[right], right--;
        if (left <= right && arr[right] > arr[left]) y += arr[right], right--;
        else if (left <= right) y += arr[left], left++;
    }
    cout << x << " " << y;
    return 0;
}
