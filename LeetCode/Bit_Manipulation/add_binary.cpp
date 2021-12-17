class Solution {
public:
    string addBinary(string &a, string &b) {
        string res = "";
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        int left = 0, right = 0;
        while (i != -1 || j != -1 || carry){
            if (i != -1)
                left = int(a[i--] - 48);
            else left = 0;
            if (j != -1)
                right = int(b[j--] - 48);
            else right = 0;
            res.insert(0, to_string((left + right + carry) % 2));
            carry = (left + right + carry)  / 2;
        }
        return  res;
    }
};
