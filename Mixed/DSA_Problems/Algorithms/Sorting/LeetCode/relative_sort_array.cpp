class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> res;
        for(auto i: arr2) res[i] = 0;
        vector<int> right;
         vector<int> left;
        for(auto i: arr1){
            if (res.find(i) != res.end()) res[i]++;
            else right.push_back(i);
        }
        sort(right.begin(), right.end());
        for(auto i: arr2){
            while(res[i] > 0){
                res[i]--;
                left.push_back(i);
            }
        }
        for(int i = 0; i < right.size(); i++)
            left.push_back(right[i]);
        return left;
    }
};
