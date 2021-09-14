class Solution {
private:
    static bool comp(int a, int b){
        string temp1 = to_string(a);
        string temp2 = to_string(b);
        return temp1 + temp2 > temp2 + temp1;
}
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string res = "";
        for(auto i: nums){
            if (res.empty() && i == 0){
                continue;
            }
            res += to_string(i) ;
        }
        return res.empty()?"0":res;
    }
};
