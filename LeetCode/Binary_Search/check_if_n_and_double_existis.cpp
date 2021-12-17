class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
        unordered_set<int> res;
        for(int & i : arr){
            if (res.find(2 * i) != res.end() || (i % 2 == 0 && res.find(i / 2) != res.end()))
                return true;
            res.insert(i);
        }
        return false;
    }
};
