#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, t, k, v, c = 0, ans = 0;

    cin >> n >> t >> k >> v;

    vector<int> h(n, 0);
    stack<int> e;

    for (int i = 0; i < v; i++) {
        int x;
        cin >> x;
        h[x - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        c += h[i];
        if (i >= t) {
            c -= h[i - t];
        }
        if (h[i] == 0) {
            e.push(i);
        }
        if (i >= t - 1) {
            while (c < k) {
                int in = e.top();
                h[in] = 1;
                c++;
                e.pop();
                ans++;
            }
        }
    }

    cout << ans << '\n';
}