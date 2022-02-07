// Ans - 1
#include <bits/stdc++.h>
using namespace std;

int constructMiniTree(int *arr, int *tree, int left, int right, int index)
{
    if (left == right){
        tree[index] = arr[left];
        return arr[left];
    }
    int mid = left + (right - left) / 2;
    tree[index] = min(constructMiniTree(arr, tree, left, mid, index * 2 + 1),
                      constructMiniTree(arr, tree, mid + 1, right, index * 2 + 2));
    return tree[index];
}

int getMin(int qleft, int qright, int left, int right, int index, int *tree){
    if (qright < left || qleft > right)
        return INT_MAX;
    if (left >= qleft && right <= qright)
        return tree[index];
    int mid = left + (right - left) / 2;
    return min(getMin(qleft, qright, left, mid, index * 2 + 1, tree),
               getMin(qleft, qright, mid + 1, right, index * 2 + 2, tree));
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
        int mini[4 * n];
        constructMiniTree(arr, mini, 0, n - 1, 0);
        vector<int> ans;
        if (arr[0] < getMin(1, n - 1, 0, n - 1, 0, mini))
            ans.push_back(0);
        int left = arr[0];
        for(int i = 1; i < n; i++)
        {
            if (left < arr[i] && arr[i] < getMin(i + 1, n - 1, 0, n - 1, 0, mini))
                ans.push_back(i);
            left = max(left, arr[i]);
        }
        cout << ans.size() << "\n";
        for(auto i: ans) cout << i << " ";
        cout << "\n";

    }
    return 0;
}

// Ans - 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
        int right[n + 1]; right[n - 1] = arr[n - 1];
        right[n] = INT_MAX;
        for(int i = n - 2; i >= 0; i--)
            right[i] = min(arr[i], arr[i + 1]);
        int left = 0;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (left < arr[i] && arr[i] < right[i + 1])
                res.push_back(i);
            left = max(left, arr[i]);
        }
        cout << res.size() << "\n";
        for(int re : res)
            cout << re << " ";
        cout << "\n";
    }
    return 0;
}
