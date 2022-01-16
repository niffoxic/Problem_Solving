#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a; cin >> n;
    int max_n = 1e5 + 1;
    long long arr[max_n], prefix[max_n], suffix[max_n], sum{0};
    vector<int> vec;
    bool res = false;
    for(int i = 0; i < n; i++){
        cin >> a;
        if (!arr[a]) vec.push_back(a);
        arr[a]++;
        sum += a;
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++){
        prefix[i] = (long long)arr[vec[i]] * (long long)vec[i] + (i == 0? 0: prefix[i - 1]);
        suffix[i] = sum - (i == 0? 0: prefix[i - 1]);
    }
    for(int i = 1; i < vec.size(); i++){
        if (prefix[i - 1] == suffix[i + 1] || prefix[i - 1] == suffix[i])
                res = true;
        if (res) break;
    }
    return cout << (res ? "YES" : "NO"), 0;
}
