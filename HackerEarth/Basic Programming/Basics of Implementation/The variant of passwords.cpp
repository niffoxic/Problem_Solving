#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, res = 0; string s; cin >> n >> a >> b >> s;
        map<char, int> req({{'0', a}, {'1', b}, {'2', n - a - b}});
        for (auto i : s) req[i]--;
        for (auto &i : s)
            if (req[i] < 0) for (char j = '0'; j < i; ++j)
                    if (req[j] > 0) {
                        req[i]++, req[j]--, i = j, res++;
                        break;
                    }
        reverse(s.begin(), s.end());
        for (auto &i : s)
            if (req[i] < 0)
                for (char j = '2'; j > i; --j)
                    if (req[j] > 0) {
                        req[i]++; req[j]--; i = j; res++;
                        break;
                    }
        reverse(s.begin(), s.end());
        cout << res << '\n' << s << '\n';
    }
    return 0;
}
