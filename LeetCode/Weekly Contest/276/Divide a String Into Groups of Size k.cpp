class Solution {
public:
    vector<string> divideString(string& s, int k, char fill) {
        vector<string> res;
        for(int i = 0; i < s.size(); i+=k){
            string current;
            for(int j = i; j < i + k; j++){
                if (j >= s.size())
                    current += fill;
                else current += s[j];
            }
            res.push_back(current);
        }
        return res;
    }
};
