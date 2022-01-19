class Solution {
public:

    bool isPalindrome(string& current){
        string s = current;
        reverse(s.begin(), s.end());
        return current == s;
    }

    string firstPalindrome(vector<string>& words) {
        for(auto & word : words){
            if (isPalindrome(word))
                return word;
        }
        return "";
    }
};
