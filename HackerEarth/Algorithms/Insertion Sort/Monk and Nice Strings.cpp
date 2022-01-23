#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string arr[1001];
    for(int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        int j = i  - 1;
        while (j >= 0 && arr[j] >= s)
            arr[j + 1] = arr[j], j--;
        cout << j << "\n";
        arr[j + 1] = s;
    }
}
