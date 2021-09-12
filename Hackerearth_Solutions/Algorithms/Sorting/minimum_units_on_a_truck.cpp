class Solution {
public:
    
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int res = 0;
        int i = 0;
        while(i < boxTypes.size() && truckSize){
            int current = min(truckSize, boxTypes[i][0]);
            res += current * boxTypes[i][1];
            i++;
            truckSize -= current;
        }
        return res;
    }
};
