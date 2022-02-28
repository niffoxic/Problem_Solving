#include <bits/stdc++.h>
using namespace std;
void answers()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    stack<int> st;
    int ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i]) st.pop();
        if (st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}

int main()
{
    answers();
    return 0;
}
