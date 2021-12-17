
class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        for(auto &i: n){
            if (i == '6'){
                i = '9';break;
            }
        }
        return stoi(n);
    }
};
