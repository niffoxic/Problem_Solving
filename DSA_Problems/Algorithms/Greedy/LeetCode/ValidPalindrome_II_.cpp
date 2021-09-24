class Solution {
public:

    bool validPalindrome(string& s1) {
        int left = 0, right = s1.size() - 1;
        int leftT = 0;
        while(left <= right){
            if (s1[left] == s1[right]){
                left++, right--;
            }else{
                leftT++;
                left++;
            }
        }
        left = 0, right = s1.size() - 1;
        int rightT = 0;
        while (left <= right){
            if (s1[left] == s1[right]){
                left++, right--;
            }else{
                rightT++;
                right--;
            }
        }
        if (rightT == 0 || leftT == 0) return true;
        if (rightT == 1 || leftT == 1) return true;
        return false;
    }
};
