#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[3][3];
    for(auto & i : arr) for(int & j : i) cin >> j;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int current = arr[i][j] + 1;
            if (i > 0) current += arr[i - 1][j];
            if (i < 2) current += arr[i + 1][j];
            if (j > 0) current += arr[i][j - 1];
            if (j < 2) current += arr[i][j + 1];
            cout << (current & 1);
        }
        cout << "\n";
    }
    return 0;
}
