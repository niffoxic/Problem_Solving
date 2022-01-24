#include <bits/stdc++.h>
using namespace std;


template <class T>
class getInversion{
public:
    T counts(T* arr, T n);
};

template<class T>
T getInversion<T>::counts(T *arr, T n) {
    multiset<int> st;
    multiset<int>::iterator it;
    T res = 0;
    if (n <= 1) return 0;
    st.insert(arr[0]);
    for (T i = 1; i < n; i++) {
        st.insert(arr[i]);
        it = st.upper_bound(arr[i]);
        res += distance(it, st.end());
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    cin >> test_case;
    getInversion<int> ans;
    while (test_case--) {
        int n, res = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << ans.counts(arr, n) << "\n";
    }
    return 0;
}
