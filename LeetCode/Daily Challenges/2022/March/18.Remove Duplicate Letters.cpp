#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string& s) {
        int index[26] = {0};
        for(int i = 0; i < s.size(); i++) index[s[i] - 'a'] = i;
        stack<char> st;
        bool visited[26]; for(bool & i : visited) i = false;
        string res;
        for(int i = 0; i < s.size(); i++)
        {
            int current = s[i] - 'a';
            if (visited[current]) continue;
            while (!st.empty() && st.top() > s[i] && i < index[st.top() - 'a'])
                visited[st.top() - 'a'] = false, st.pop();
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        while (!st.empty()) res += st.top(), st.pop();
        reverse(res.begin(), res.end());
        return res;
    }
};
