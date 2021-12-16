class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int check = 0;
        for(auto i: arr) check += i;
        if (check % 3) return false;
        int req = check / 3;
        int res = 0, sum = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            sum += arr[i];
            if (!res && sum == req)
                res++;
            else if (res && sum == 2 * req){
                res++; break;
            }
        }
        return res == 2;
    }
};
