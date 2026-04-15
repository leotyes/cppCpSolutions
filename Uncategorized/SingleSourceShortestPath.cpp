#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> vd(n + 1, -1);
    vector<vector<pair<int, int>>> vadj(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vadj[u].emplace_back(w, v);
        vadj[v].emplace_back(w, u);
    }

    pq.emplace(0, 1);
    vd[1] = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        for (auto [nw, v] : vadj[u]) {
            if (vd[v] == -1 || vd[v] > vd[u] + nw) {
                vd[v] = vd[u] + nw;
                pq.emplace(nw, v);
            }
        }
    }

    bool s = false;
    for (int x : vd) {
        if (!s) {
            s = true;
            continue;
        }
        cout << x << "\n";
    }
}