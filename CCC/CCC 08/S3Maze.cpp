#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) {
        int r, c;

        cin >> r >> c;
        vector<string> vg(r);
        vector<vector<bool>> vis(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++) {
            cin >> vg[i];
        }

        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, 1);
        bool f = false;

        while (!q.empty()) {
            auto [cr, cc, cd] = q.front();
            if (cr == r - 1 && cc == c - 1) {
                cout << cd << "\n";
                f = true;
                break;
            }
            switch (vg[cr][cc]) {
                case '|':
                    if (cr > 0 && vg[cr - 1][cc] != '*' && !vis[cr - 1][cc]) {
                        vis[cr - 1][cc] = true;
                        q.emplace(cr - 1, cc, cd + 1);
                    }
                    if (cr < r - 1 && vg[cr + 1][cc] != '*' && !vis[cr + 1][cc]) {
                        vis[cr + 1][cc] = true;
                        q.emplace(cr + 1, cc, cd + 1);
                    }
                    break;
                case '-':
                    if (cc > 0 && vg[cr][cc - 1] != '*' && !vis[cr][cc - 1]) {
                        vis[cr][cc - 1] = true;
                        q.emplace(cr, cc - 1, cd + 1);
                    }
                    if (cc < c - 1 && vg[cr][cc + 1] != '*' && !vis[cr][cc + 1]) {
                        vis[cr][cc + 1] = true;
                        q.emplace(cr, cc + 1, cd + 1);
                    }
                    break;
                case '+':
                    if (cr > 0 && vg[cr - 1][cc] != '*' && !vis[cr - 1][cc]) {
                        vis[cr - 1][cc] = true;
                        q.emplace(cr - 1, cc, cd + 1);
                    }
                    if (cr < r - 1 && vg[cr + 1][cc] != '*' && !vis[cr + 1][cc]) {
                        vis[cr + 1][cc] = true;
                        q.emplace(cr + 1, cc, cd + 1);
                    }
                    if (cc > 0 && vg[cr][cc - 1] != '*' && !vis[cr][cc - 1]) {
                        vis[cr][cc - 1] = true;
                        q.emplace(cr, cc - 1, cd + 1);
                    }
                    if (cc < c - 1 && vg[cr][cc + 1] != '*' && !vis[cr][cc + 1]) {
                        vis[cr][cc + 1] = true;
                        q.emplace(cr, cc + 1, cd + 1);
                    }
                    break;
            }
            q.pop();
        }
        if (!f) {
            cout << -1 << "\n";
        }
    }
}