#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = -1;

    cin >> n >> m;

    vector<string> vg(n);
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < n; i++) {
        cin >> vg[i];

        for (int j = 0; j < m; j++) {
            if (vg[i][j] == 's') {
                q.emplace(i, j, 0);
                vg[i][j] = 'X';
            }
        }
    }

    while (!q.empty()) {
        auto [cr, cc, ct] = q.front();

        if (vg[cr][cc] == 'e') {
            ans = ct;
            break;
        }

        if (cr > 0 && vg[cr - 1][cc] != 'X') {
            if (vg[cr - 1][cc] != 'e') {
                vg[cr - 1][cc] = 'X';
            }
            q.emplace(cr - 1, cc, ct + 1);
        }
        if (cr < n - 1 && vg[cr + 1][cc] != 'X') {
            if (vg[cr + 1][cc] != 'e') {
                vg[cr + 1][cc] = 'X';
            }
            q.emplace(cr + 1, cc, ct + 1);
        }
        if (cc > 0 && vg[cr][cc - 1] != 'X') {
            if (vg[cr][cc - 1] != 'e') {
                vg[cr][cc - 1] = 'X';
            }
            q.emplace(cr, cc - 1, ct + 1);
        }
        if (cc < m - 1 && vg[cr][cc + 1] != 'X') {
            if (vg[cr][cc + 1] != 'e') {
                vg[cr][cc + 1] = 'X';
            }
            q.emplace(cr, cc + 1, ct + 1);
        }

        q.pop();
    }

    if (ans == -1) {
        cout << ans;
    } else {
        cout << ans - 1;
    }
}