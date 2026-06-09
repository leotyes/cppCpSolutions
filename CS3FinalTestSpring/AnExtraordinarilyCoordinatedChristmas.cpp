#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> vadj;
int md = 0, e;
vector<int> vde1, vde2;

void dfs(int cur, int p, int cw, int m) {
    for (auto [v, w] : vadj[cur]) {
        if (v == p) continue;
        if (w + cw > md) {
            md = w + cw;
            e = v;
        }
        if (m == 1) {
            vde1[v] = w + cw;
        } else if (m == 2) {
            vde2[v] = w + cw;
        }
        dfs(v, cur, w + cw, m);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, e1, e2;
    cin >> n >> q;
    vadj.resize(n + 1);
    vde1.resize(n + 1, 0);
    vde2.resize(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vadj[u].emplace_back(v, w);
        vadj[v].emplace_back(u, w);
    }
    dfs(1, 0, 0, 0);
    e1 = e;
    e = 0;
    md = 0;
    dfs(e1, 0, 0, 1);
    e2 = e;
    e = 0;
    md = 0;
    dfs(e2, 0, 0, 2);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << max(vde1[x], vde2[x]) << "\n";
    }
}