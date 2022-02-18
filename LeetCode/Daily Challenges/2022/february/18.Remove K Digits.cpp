class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() <= k) return "0";
        string res;
        stack<char> st;
        st.push(num[0]);
        for(int i = 1; i < num.size(); i++){
            while(k > 0 && !st.empty() && num[i] < st.top()){
                k--;
                st.pop();
            }
            st.push(num[i]);
            if (st.size() == 1 && num[i] == '0') st.pop();
        }
        while(k && !st.empty()){
            k--; st.pop();
        }
        while(!st.empty()){
            res += st.top(); st.pop();
        }
        reverse(res.begin(), res.end());
        return res == ""? "0": res;
    }
};
