#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    vector<vector<int>> vd(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++) {
        cin >> vs[i];
    }

    queue<pair<int, int>> q;
    string ans = "";
    q.emplace(0, 0);
    vector<char> vmc(4002, 'z' + 1);
    vmc[0] = vs[0][0];
    vd[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int d = vd[x][y];
        if (vmc[d] != vs[x][y]) continue;
        if (x != n - 1 && vd[x + 1][y] == INT_MAX && vs[x + 1][y] <= vmc[d + 1]) {
            vd[x + 1][y] = d + 1;
            q.emplace(x + 1, y);
            vmc[d + 1] = vs[x + 1][y];
        }
        if (y != m - 1 && vd[x][y + 1] == INT_MAX && vs[x][y + 1] <= vmc[d + 1]) {
            vd[x][y + 1] = d + 1;
            q.emplace(x, y + 1);
            vmc[d + 1] = vs[x][y + 1];
        }
    }

    for (int i = 0; i < n + m - 1; i++) {
        cout << vmc[i];
    }
}