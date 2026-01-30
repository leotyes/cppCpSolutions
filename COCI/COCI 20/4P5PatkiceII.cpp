// use 0-1 weighted bfs to track changes
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, s, dr, dc, sr, sc;
    map<char, vector<int>> m = {{'>', {0, 1}}, {'<', {0, -1}}, {'v', {1, 0}}, {'^', {-1, 0}}};
    map<vector<int>, char> mv = {{{0, 1}, '>'}, {{0, -1}, '<'}, {{1, 0}, 'v'}, {{-1, 0}, '^'}};
    set<tuple<int, int, char>> sac;

    cin >> r >> s;

    vector<vector<char>> vg(r, vector<char>(s));
    vector<vector<int>> vd(r, vector<int>(s, INT_MAX));
    vector<vector<vector<int>>> vp(r, vector<vector<int>>(s, vector<int>(2, -1)));
    deque<tuple<int, int, vector<int>>> dq;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            cin >> vg[i][j];
            if (vg[i][j] == 'o') {
                vd[i][j] = 0;
                sr = i;
                sc = j;
                dq.emplace_back(i, j, vector<int>{0, 0});
            } else if (vg[i][j] == 'x') {
                dr = i;
                dc = j;
            }
        }
    }

    while (!dq.empty()) {
        auto [cr, cc, cp] = dq.front();
        dq.pop_front();

        for (auto [c, p] : m) {
            int nr = cr + p[0], nc = cc + p[1];

            if (nr >= 0 && nr < r && nc >= 0 && nc < s) {
                if (c != vg[cr][cc] && vg[cr][cc] != 'o') {
                    if (vd[cr][cc] + 1 < vd[nr][nc]) {
                        vp[nr][nc] = vector<int>{cr, cc};
                        vd[nr][nc] = vd[cr][cc] + 1;
                        if (!(nr == dr && nc == dc)) dq.emplace_back(nr, nc, vector<int>{cr, cc});
                    }
                } else {
                    if (vd[cr][cc] < vd[nr][nc]) {
                        vp[nr][nc] = vector<int>{cr, cc};
                        vd[nr][nc] = vd[cr][cc];
                        if (!(nr == dr && nc == dc)) dq.emplace_front(nr, nc, vector<int>{cr, cc});
                    }
                }
            }
        }
    }

    int cr = dr, cc = dc;

    while (!(vp[cr][cc][0] == sr && vp[cr][cc][1] == sc)) {
        if (vp[cr][cc][0] == sr && vp[cr][cc][1] == sc) break;
        vg[vp[cr][cc][0]][vp[cr][cc][1]] = mv[{cr - vp[cr][cc][0], cc - vp[cr][cc][1]}];
        int ncr = vp[cr][cc][0];
        cc = vp[cr][cc][1];
        cr = ncr;
    }

    cout << vd[dr][dc] << "\n";

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            cout << vg[i][j];
        }
        cout << "\n";
    }
}