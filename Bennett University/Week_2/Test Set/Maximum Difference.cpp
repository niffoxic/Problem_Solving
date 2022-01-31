#include <bits/stdc++.h>
using namespace std;

#if 0
    Maximum Difference (my rating -> cake walk)

    Question - Given a matrix of size N * M where N represent
    number of rows and M represents number of columns.

    For a row we define a value called DiffValue which
    is difference between its largest term and the smallest
    term i.e (maximum term - minimum term). You have to answer
    the largest DiffValue among all the rows for the given matrix.
#endif

int main() {
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        int res = INT_MIN;
        for(int i = 0; i < n; i++){
            int a = INT_MAX, b = INT_MIN;
            for(int j = 0; j < m; j++){
                int c; cin >> c;
                a = min(c, a), b = max(b, c);
            }
            res = max(res, b - a);
        }
        cout << res << "\n";
    }
    return 0;
}
