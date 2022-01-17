class Solution {
public:
    bool checkString(string& s) {
        bool res = true;
        for(auto i: s){
            if (i == 'b')
                res = false;
            if (!res && i == 'a')
                return false;
        }
        return true;
    }
};
