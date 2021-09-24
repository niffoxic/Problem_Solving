class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = (int)flowerbed.size();
        if (!n || (n == 1 && flowerbed[0] == 0 && len == 1)) return true;
        if (len >= 2 && flowerbed[0] + flowerbed[1] == 0){
            n--;
            flowerbed[0] = 1;
        }
        if (len >= 2 && flowerbed[len - 1] + flowerbed[len - 2] == 0){
            n--;
            flowerbed[len - 1] = 1;
        }
        if (n <= 0) return true;
        for(int i = 1; i < len - 1; i++){
            if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0){
                n--;
                flowerbed[i] = 1;
            }
            if (n <= 0) return true;
        }
        return false;
    }
};
