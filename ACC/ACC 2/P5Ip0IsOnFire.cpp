#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<vector<pair<int, int>>> vadj(n + 1, vector<pair<int, int>>());
    vector<int> vd(n + 1, LLONG_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    set<int> sk;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        sk.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        vadj[u].emplace_back(d, v);
        vadj[v].emplace_back(d, u);
    }
    for (int i = 1; i <= n; i++) {
        if (sk.find(i) == sk.end()) {
            pq.emplace(0, i);
            vd[i] = 0;
        }
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        for (auto [nd, v] : vadj[u]) {
            if (vd[u] + nd < vd[v]) {
                vd[v] = vd[u] + nd;
                pq.emplace(nd, v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (vd[i] > t ? 1 : 0);
    }
}