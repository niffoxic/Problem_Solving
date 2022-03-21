// best

class Solution {
public:
    vector<int> partitionLabels(string& s) {
        int last[26], n = s.size(), left = 0, right = 0;
        for(int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;
        vector<int> res;
        for(int i = 0; i < n; i++){
            right = max(right, last[s[i] - 'a']);
            if (right == i){
                res.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return res;
    }
};

// Initial

class Solution {
public:
    vector<int> partitionLabels(string& s) {
        unordered_map<char, int> mp;
        unordered_set<char> st;
        vector<int> res;
        int n = s.size();
        for(auto i: s) mp[i]++;
        int len = 0;
        for(int i = 0; i < n; i++){
            mp[s[i]]--;
            len++;
            st.insert(s[i]);
            if (!mp[s[i]]) st.erase(s[i]);
            if (!st.size()) res.push_back(len), len = 0;
        }
        return res;
    }
};
