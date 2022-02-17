class SolutionInitial {
private: set<vector<int>> res;

public:

    void solve(vector<int>& candidates, int needed, int index, vector<int> current)
    {
        if (needed == 0)
            res.insert(current);
        if (needed < 0 || index == candidates.size()) return;
        vector<int> changed = current; changed.push_back(candidates[index]);
        solve(candidates, needed - candidates[index], index, changed);
        solve(candidates, needed, index + 1, current);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.erase(res.begin(), res.end());
        vector<int> temp;
        solve(candidates, target, 0, temp);
        vector<vector<int>> ans; for(auto i: res) ans.push_back(i);
        return ans;
    }
};

class SolutionOptimized{
private:
    vector<vector<int>> res;
public:

    void solve(vector<int>& candidates, int needed, vector<int>& current, int index){
        if (needed == 0){
            res.push_back(current);
            return;
        }
        while (index < candidates.size() && needed - candidates[index] >= 0){
            current.push_back(candidates[index]);
            solve(candidates, needed - candidates[index], current, index);
            index++;
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        vector<int> current;
        solve(candidates, target, current, 0);
        return res;
    }
};
