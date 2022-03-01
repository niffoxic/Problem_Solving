class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int i = 1; i <= n; i++){
            int temp = i, c = 0;
            while (temp){
                temp &= (temp - 1);
                c++;
            }
            res[i] = c;
        }
        return res;
    }
};
