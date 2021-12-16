class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (arr.size() != target.size())
            return false;
        unordered_map<int, int> res;
        for(int i = 0; i < arr.size(); i++){
            res[target[i]]++;
            res[arr[i]]--;
        }
        for(auto i: res){
            if (i.second != 0)
                return false;
        }
        return true;
    }
};
