#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, b, q;
    cin >> n >> m >> b >> q;
    vector<vector<pair<int, int>>> vadj(n + 1, vector<pair<int, int>>());
    vector<int> vd(n + 1, INT_MAX);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vadj[x].emplace_back(z, y);
        vadj[y].emplace_back(z, x);
    }
    vd[b] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, b);

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        for (auto [nw, u] : vadj[v]) {
            if (vd[v] + nw < vd[u]) {
                vd[u] = vd[v] + nw;
                pq.emplace(nw, u);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (vd[x] == INT_MAX) {
            cout << -1 << "\n";
        } else {
            cout << vd[x] << "\n";
        }
    }
}