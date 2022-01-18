
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string& s) {
        vector<int> res;
        for(int i = 0; i < s.size(); i++)
        {
            int current = 0;
            vector<int> pos = startPos;
            for(int j = i; j < s.size(); j++){
                if (s[j] == 'L') pos[1]--;
                else if (s[j] == 'R') pos[1]++;
                else if (s[j] == 'U')pos[0]--;
                else pos[0]++;

                if (pos[0] < 0 || pos[1] < 0 || pos[0] == n || pos[1] == n)
                    break;
                current++;
            }
            res.push_back(current);
        }
        return res;
    }
};
