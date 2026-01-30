#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int gd(char c, int d, bool f) {
    if ((c == '/' && !f) || (c == '\\' && f)) {
        return d % 2 == 1 ? (d + 1) % 4 : (d - 1 + 4) % 4;
    }
    return d % 2 == 1 ? (d - 1 + 4) % 4 : (d + 1) % 4;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = INT_MAX;

    cin >> n >> m;

    vector<vector<char>> vg(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vg[i][j];
        }
    }

    vector<vector<vector<int>>> vd(n + 1, vector<vector<int>>(m, vector<int>(4, INT_MAX)));
    deque<tuple<int, int, int>> dq;
    vd[0][0][0] = 0;
    bool f = false;
    dq.emplace_back(0, 0, 0);
    while (!dq.empty()) {
        auto [cr, cc, cd] = dq.front();
        dq.pop_front();

        int nd = gd(vg[cr][cc], cd, false), nr = cr + dir[nd][0], nc = cc + dir[nd][1];
        if (nr == n && nc == m - 1 && nd == 0) {
            f = true;
            ans = min(ans, vd[cr][cc][cd]);
        }
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && vd[cr][cc][cd] < vd[nr][nc][nd]) {
            vd[nr][nc][nd] = vd[cr][cc][cd];
            dq.emplace_front(nr, nc, nd);
        }
        nd = gd(vg[cr][cc], cd, true), nr = cr + dir[nd][0], nc = cc + dir[nd][1];
        if (nr == n && nc == m - 1 && nd == 0) {
            f = true;
            ans = min(ans, vd[cr][cc][cd] + 1);
        }
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && vd[cr][cc][cd] + 1 < vd[nr][nc][nd]) {
            vd[nr][nc][nd] = vd[cr][cc][cd] + 1;
            dq.emplace_back(nr, nc, nd);
        }
    }

    if (!f) cout << -1; else {
        cout << ans;
    }
}