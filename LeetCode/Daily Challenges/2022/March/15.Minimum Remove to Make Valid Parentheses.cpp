class Solution {
public:
    string minRemoveToMakeValid(string& s) {
        stack<int> st;
        unordered_set<int> inValidIndex;
        for(int i = 0; i < s.size(); i++){
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')'){
                if (st.empty()){
                    inValidIndex.insert(i); continue;
                }
                st.pop();
            }
        }
        while (!st.empty()) inValidIndex.insert(st.top()), st.pop();
        string res;
        for(int i = 0; i < s.size(); i++){
            if (inValidIndex.find(i) == inValidIndex.end()) res += s[i];
        }
        return res;
    }
};
