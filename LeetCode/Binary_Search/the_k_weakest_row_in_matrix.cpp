class Solution {
public:

    int bin(vector<int> & arr){
        int left = 0, right = arr.size() - 1, mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if (arr[mid] < 1){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> res;
        for(int i = 0; i < mat.size(); i++){
            int temp = bin(mat[i]);
            res.emplace_back(temp, i);
        }
        vector<int> ans;
        sort(res.begin(), res.end());
        for(int i = 0; i < k; i++) ans.push_back(res[i].second);

        return ans;
    }
};
