class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for(int i = 0; i < digits.size(); i++){
            if (carry){
                carry = (digits[i] + 1) / 10;
                digits[i] = (digits[i] + 1) % 10;
            }else break;
        }
        if (carry)
            digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
