#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0, n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b){
                 return a[1] < b[1];
        });
        for(int i = 0; i < n; i++) cout << intervals[i][0] << " " << intervals[i][1] << " | ";
        int end = intervals[0][1];
        for(int i = 1; i < n; i++){
            if (intervals[i][0] < end) res++;
            else end = intervals[i][1];
        }
        return res;
    }
};
