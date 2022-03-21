#include <bits/stdc++.h>

using namespace std;

#define template_size 200005
using ll = long long;
int test, n, arr[template_size];
priority_queue<ll> pq;

int main() {
    cin >> test;
    while (test--) {
        cin >> n;
        while (!pq.empty()) pq.pop();
        ll sum = 0;
        for (int i = 1; i <= n; i++) cin >> arr[i], sum += arr[i];
        sort(arr + 1, arr + n + 1);
        pq.push(sum);
        bool res = true;
        for (int i = n; i >= 1 && res; i--) {
            while (res) {
                ll u = pq.top();
                pq.pop();
                if (u < arr[i]) res = false;
                if (u == arr[i]) break;
                pq.push(u / 2);
                pq.push((u + 1) / 2);
            }
        }
        cout << (res? "YES": "NO") << "\n";
    }
    return 0;
}
