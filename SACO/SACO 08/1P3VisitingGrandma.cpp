#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    vector<vector<int>> vadj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vadj[i][j];
        }
    }
    cin >> m;
    vector<vector<int>> vd(n, vector<int>(2, LLONG_MAX)), vp(n, vector<int>(2, 0));
    int init = 0;
    set<int> vc;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        if (x == 0) init = 1;
        vc.insert(x);
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    pq.emplace(0, 0, init);
    vd[0][init] = 0;
    vp[0][init] = 1;

    while (!pq.empty()) {
        auto [d, u, ec] = pq.top();
        pq.pop();
        if (d != vd[u][ec]) continue;
        for (int v = 0; v < n; v++) {
            int nd = vadj[u][v], nec = ec;
            if (nd == 0) continue;
            if (vc.find(v) != vc.end()) {
                nec = true;
            }
            if (nd + vd[u][ec] < vd[v][nec]) {
                vp[v][nec] = vp[u][ec];
                vd[v][nec] = nd + vd[u][ec];
                pq.emplace(nd + vd[u][ec], v, nec);
            } else if (nd + vd[u][ec] == vd[v][nec]) {
                vp[v][nec] += vp[u][ec];
                vp[v][nec] %= 1000000;
            }
        }
    }

    int mind = vd[n - 1][1], numd = vp[n - 1][1];

    cout << mind << " " << numd % 1000000;
}