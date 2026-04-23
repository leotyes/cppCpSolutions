#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d;
    cin >> n >> m;
    vector<vector<pair<int, int>>> vadj(n + 1, vector<pair<int, int>>()), vadjr(n + 1, vector<pair<int, int>>());
    vector<tuple<int, int, int>> vc;
    vector<int> vd(n + 1, LLONG_MAX), vdr(n + 1, LLONG_MAX);
    for (int i = 0; i < m; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        vadj[a].emplace_back(k, b);
        vadjr[b].emplace_back(k, a);
    }
    cin >> d;
    for (int i = 0; i < d; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        vc.emplace_back(a, b, g);
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

    int ans = vd[n];

    for (auto [a, b, g] : vc) {
        if (vd[a] + vdr[b] >= 0 && vd[a] + vdr[b] + g >= 0) {
            ans = min(ans, vd[a] + g + vdr[b]);
        }
    }

    if (ans == LLONG_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }
}