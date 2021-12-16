class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> res;
        unordered_map<int, int> ans;
        for(auto i: arr) res.insert(i);
        int ranks = 1;
        for(auto i: res){
            ans[i] = ranks;
            ranks++;
        }
        vector<int> fs;
        for(int i = 0; i < arr.size(); i++){
            fs.push_back(ans[arr[i]]);
        }
        return fs;
    }
};
