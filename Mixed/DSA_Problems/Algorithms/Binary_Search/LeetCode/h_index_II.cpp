class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if (citations[mid] >= citations.size() - mid){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return citations.size() - left;
    }
};
