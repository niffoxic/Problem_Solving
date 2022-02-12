

class Solution {
public:
    bool checkInclusion(string& s1, string& s2)
    {
        vector<int> a(26, 0), b(26, 0);
        for(auto &i: s1) a[i - 'a']++;

        for(int i = 0; i < s2.size(); i++)
        {
            b[s2[i] - 'a']++;
            if (i >= s1.size() - 1)
            {
                if (a == b) return true;
                b[s2[i - s1.size() + 1] - 'a']--;
            }
        }
        return false;
    }
};
