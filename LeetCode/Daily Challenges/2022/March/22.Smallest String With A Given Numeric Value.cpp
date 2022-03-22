
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        for(int i = 0; i < n; i++) res += 'a';
        k -= n;
        for(int j = n - 1; j >= 0 && k; j--){
            if (k >= 26) k -= 25, res[j] = 'z';
            else res[j] = 'a' + (k), k = 0;
        }
        return res;
    }
};
