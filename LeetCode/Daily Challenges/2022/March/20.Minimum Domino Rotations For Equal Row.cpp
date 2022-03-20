class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int majority = tops[0], counts = 1;
        if (bottoms[0] == majority) counts++;
        else majority = bottoms[0], counts = 1;
        for(int i = 1; i < tops.size(); i++){
            if (tops[i] == majority) counts++;
            else counts--;
            if (!counts) counts = 1, majority = tops[i];
            if (bottoms[i] == majority) counts++;
            else counts--;
            if (!counts) counts = 1, majority = bottoms[i];
        }
        int up = 0, down = 0;
        for(int i = 0; i < tops.size(); i++){
            if (tops[i] != majority && bottoms[i] != majority) return -1;
            if (tops[i] != majority) up++;
            if (bottoms[i] != majority) down++;
        }
        return min(up, down);
    }
};
