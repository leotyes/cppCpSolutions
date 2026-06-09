#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n, m, a, b;
    cin >> k >> n >> m;
    vector<vector<tuple<int, int, int>>> vadj(n + 1, vector<tuple<int, int, int>>());
    vector<vector<int>> vd(n + 1, vector<int>(k + 1, LLONG_MAX));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;

    for (int i = 0; i < m; i++) {
        int ai, bi, t, h;
        cin >> ai >> bi >> t >> h;
        vadj[ai].emplace_back(t, h, bi);
        vadj[bi].emplace_back(t, h, ai);
    }

    cin >> a >> b;

    pq.emplace(0, 0, a, k);
    vd[a][k] = 0;

    while (!pq.empty()) {
        auto [t, h, u, ch] = pq.top();
        pq.pop();
        for (auto [nt, nh, v] : vadj[u]) {
            if (ch - nh <= 0) {
                continue;
            }
            if (vd[u][ch] + nt < vd[v][ch - nh]) {
                pq.emplace(nt, nh, v, ch - nh);
                vd[v][ch - nh] = vd[u][ch] + nt;
            }
        }
    }

    int ans = *min_element(vd[b].begin(), vd[b].end());

    cout << (ans == LLONG_MAX ? -1 : ans);
}