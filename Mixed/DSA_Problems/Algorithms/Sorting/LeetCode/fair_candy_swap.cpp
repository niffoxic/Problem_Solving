#define all(x) x.begin(), x.end()
class Solution {
public:

    int bin(vector<int> &bb, int selected, int a_sum, int b_sum){
        int left = 0, right = bb.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int lhs = a_sum - selected + bb[mid];
            int rhs = b_sum - bb[mid] + selected;
            if (lhs == rhs){
                return bb[mid];
            }else if(lhs > rhs){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return -1;
    }

    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice = 0, bob = 0;
        sort(all(aliceSizes));
        sort(all(bobSizes));
        for(auto i: aliceSizes) alice += i;
        for(auto i: bobSizes) bob += i;

        for(auto i: aliceSizes){
            int current = bin(bobSizes, i, alice, bob);
            if (current != -1)
                return {i, current};
        }
        return {-1, -1};
    }
};
