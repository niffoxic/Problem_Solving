#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int res = 0;
        unordered_set<string> sw;
        for(auto &i: startWords){
            sort(i.begin(), i.end());
            sw.insert(i);
        }
        for(auto &i: targetWords){
            sort(i.begin(), i.end());
            for(int j = 0; j < i.size(); j++){
                if (sw.find(i.substr(0, j) + i.substr(j + 1)) != sw.end()){
                    res++; break;
                }
            }
        }
        return res;
    }
};

