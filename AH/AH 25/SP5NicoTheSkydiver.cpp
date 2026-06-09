#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, ct = 0;
        cin >> n;
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++) {
            int ti, di;
            cin >> ti >> di;
            vp[i] = make_pair(di, ti);
        }

        sort(vp.begin(), vp.end());
        priority_queue<int> pq;

        for (auto [di, ti] : vp) {
            ct += ti;
            pq.push(ti);
            if (ct > di) {
                ct -= pq.top();
                pq.pop();
            }
        }

        cout << pq.size() << "\n";
    }
}