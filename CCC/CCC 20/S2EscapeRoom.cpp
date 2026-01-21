#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>> madj;
vector<vector<int>> vg;
vector<vector<bool>> vb;
int m, n;
bool d = false;

void dfs(pair<int, int> cur, int curv) {
    if (cur.first == m && cur.second == n) {
        cout << "yes";
        d = true;
        return;
    }
    if (d) return;
    for (auto x : madj[curv]) {
        if (!vb[x.first][x.second]) {
            vb[x.first][x.second] = true;
            dfs(x, vg[x.first][x.second]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    vg.resize(m + 1, vector<int>(n + 1));
    vb.resize(m + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> vg[i][j];
            madj[i * j].emplace_back(i, j);
        }
    }

    vb[1][1] = true;
    dfs(make_pair(1, 1), vg[1][1]);

    if (!d) cout << "no";
}