#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k; cin >> n >> k;
    int diagonal = (k / n) * n;
    int remainder = k % n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j)
                cout << diagonal << " ";
            else if (k % n && j == n - 1 && !i)
                cout << remainder;
            else if (i > 0 && i - 1 == j)
                cout << remainder << " ";
            else cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}
