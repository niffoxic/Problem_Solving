class Solution {
public:
    vector<int> diStringMatch(string& s1) {
        int n = (int)s1.size();
        vector<int>res(n + 1);
        int left = 0, right = n;
        for(int i = 0; i <= n; i++){
            if (s1[i] == 'D')
                res[i] = right--;
            else
                res[i] = left++;
        }
        return res;
    }
};
