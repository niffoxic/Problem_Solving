
class Solution {
public:

    unordered_map<int, int> bank;

    bool person(int value){
        if (value == 5) bank[5]++;
        else if (value == 10){
            if (bank[5] < 0)
                return false;
            bank[5]--;
            bank[10]++;
        }
        else{
            if (bank[10]){
                bank[10]--;
                if (bank[5] > 0) bank[5]--;
                else return false;
            }else{
                if (bank[5] >= 3){
                    bank[5] -= 3;
                }else return false;
            }
        }
        return true;
    }

    bool lemonadeChange(vector<int>& bills) {
        for(auto i: bills) if (!person(i)) return false;
        return true;
    }
};
