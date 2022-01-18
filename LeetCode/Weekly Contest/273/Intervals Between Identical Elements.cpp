class Solution {
public:
    vector<long long> getDistances(vector<int> &arr) {
        int n = arr.size();
        vector<long long int> ans(n, 0);
        map<long long int, pair<long long int, long long int> > map1, map2;
        for (int i = 0; i < n; i++) {
            ans[i] += (map1[arr[i]].second * i - map1[arr[i]].first);
            map1[arr[i]].first += i;
            map1[arr[i]].second++;
        }
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += (map2[arr[i]].first - i * map2[arr[i]].second);
            map2[arr[i]].first += i;
            map2[arr[i]].second++;
        }
        return ans;
    }
};
