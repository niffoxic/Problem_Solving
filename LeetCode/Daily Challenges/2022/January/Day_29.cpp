class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        stack<int> st;
        for(int i = 0; i <= n; i++)
        {
            int current = i == n? 0: heights[i];
            while (!st.empty() && current < heights[st.top()])
            {
                int index = st.top(); st.pop();
                int w = st.empty()? i: i - st.top() - 1;
                res = max(res,  heights[index] * w);
            }
            st.push(i);
        }
        return res;
    }
};
