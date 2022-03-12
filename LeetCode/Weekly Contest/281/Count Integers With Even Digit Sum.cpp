class Solution {
public:

    int getSum(int x){
        int c = 0;
        while (x) c += x % 10, x /= 10;
        return c;
    }
    int countEven(int num) {
        int res = 0;
        for(int i = 2; i <= num; i++){
            int current = getSum(i);
            if (current && !(current & 1)) res++;
        }
        return res;
    }
};
