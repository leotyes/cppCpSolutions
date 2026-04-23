#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, minr = LLONG_MAX;
    cin >> n >> m;
    vector<vector<pair<int, int>>> vadj(n + 1, vector<pair<int, int>>()), vadjr(n + 1, vector<pair<int, int>>());
    vector<int> vd(n + 1, LLONG_MAX), vdr(n + 1, LLONG_MAX);
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        vadj[a].emplace_back(l, b);
        vadjr[b].emplace_back(l, a);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq, pqr;
    vd[1] = 0;
    vdr[n] = 0;
    pq.emplace(0, 1);
    pqr.emplace(0, n);

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        for (auto [nw, v] : vadj[u]) {
            if (vd[u] + nw < vd[v]) {
                vd[v] = vd[u] + nw;
                pq.emplace(nw, v);
            }
        }
    }

    while (!pqr.empty()) {
        auto [w, u] = pqr.top();
        pqr.pop();
        for (auto [nw, v] : vadjr[u]) {
            if (vdr[u] + nw < vdr[v]) {
                vdr[v] = vdr[u] + nw;
                pqr.emplace(nw, v);
            }
        }
    }

    int ans = LLONG_MAX;
    bool f = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < vadj[i].size(); j++) {
            auto [w, v] = vadj[i][j];
            if (vd[i] != LLONG_MAX && vdr[v] != LLONG_MAX && vd[i] + vdr[v] + w > vd[n]) {
                f = true;
                ans = min(ans, vd[i] + vdr[v] + w);
            }
        }
    }

    if (!f) {
        cout << -1;
    } else {
        cout << ans;
    }
}