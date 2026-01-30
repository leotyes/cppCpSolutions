#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, q, ans = 0;

    cin >> n >> k >> q;

    vector<vector<int>> vg(n + 1, vector<int>(n + 1, 0)), vs(n + 1, vector<int>(n + 1));

    while (q--) {
        int r, c, v;

        cin >> r >> c >> v;

        int dif = v - vg[r][c];
        vg[r][c] = v;

        for (int i = max(0, r - k + 1); i <= r; i++) {
            for (int j = max(0, c - k + 1); j <= c; j++) {
                vs[i][j] += dif;
                if (vs[i][j] > ans) ans = vs[i][j];
            }
        }

        cout << ans << "\n";
    }
}