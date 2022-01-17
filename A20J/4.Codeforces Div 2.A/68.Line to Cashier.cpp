#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> res;
    for(auto i: arr)
    {
        int current = 0;
        for(int j = 0; j < i; j++)
        {
            int t; cin >> t;
            current += t * 5;
        }
        current += 15 * i;
        res.push_back(current);
    }
    return cout << *min_element(res.begin(), res.end()), 0;
}
