/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = INT_MAX;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int current = guess(mid);
            if (current == 0) return mid;
            else if (current == -1)
                right = mid - 1;
            else left = mid + 1;
        }
        return 0;
    }
};
