#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    int arr[] = {4, 7, 44, 47, 74, 444, 447, 474, 477,
                 744, 747, 774, 777};
    bool res = false;
    for(int i = 0; i < 13 && !res; i++)
        if (arr[i] == n || !(n % arr[i]))
            res = true;
    cout << ((res)? "YES": "NO");
}
