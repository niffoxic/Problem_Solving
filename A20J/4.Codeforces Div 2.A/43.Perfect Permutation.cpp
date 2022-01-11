#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin >> n;
    int arr[n + 1]; for(int i = 1; i <= n; i++) arr[i] = i;
    if (n % 2) cout << -1;
    else {
        for(int i = 1; i <= n - 1; i+=2)
            cout << arr[i + 1] << " " << arr[i] << " ";
    }
}
