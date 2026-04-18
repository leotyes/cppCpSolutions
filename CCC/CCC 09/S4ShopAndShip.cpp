#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, k, d;
    cin >> n >> t;
    vector<vector<pair<int, int>>> vadj(n + 1, vector<pair<int, int>>());
    vector<long long> vd(n + 1, LLONG_MAX);
    vector<pair<int, int>> vp;
    for (int i = 0; i < t; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        vadj[x].emplace_back(c, y);
        vadj[y].emplace_back(c, x);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int z, p;
        cin >> z >> p;
        vp.emplace_back(z, p);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    cin >> d;
    pq.emplace(0, d);
    vd[d] = 0;

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

    long long ans = LLONG_MAX;

    for (auto [z, p] : vp) {
        if (p + vd[z] < 0) continue;
        ans = min(ans, p + vd[z]);
    }

    cout << ans;
}