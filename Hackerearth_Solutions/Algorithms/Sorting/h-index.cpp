class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int index = -1;
        for(int i = 0; i < citations.size(); i++){
            index = citations.size() - i;
            bool left = false, right = false;
            if (i - 1 >= 0){
                if (citations[i - 1] <= index) left = true;
            }else left = true;
            if (i < citations.size()){
                if (citations[i] >= index) right = true;
            }else right = true;
            if (left && right) return index;
        }
        return 0;
    }
};
