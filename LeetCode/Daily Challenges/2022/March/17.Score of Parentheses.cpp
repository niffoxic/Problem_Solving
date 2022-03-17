class Solution {
public:
    int scoreOfParentheses(string& s) {
        stack<int> st;
        int current = 0;
        for(auto i: s){
            if (i == '(') st.push(current), current = 0;
            else current = st.top() + max(2 * current, 1), st.pop();
        }
        return st.top();
    }
};
