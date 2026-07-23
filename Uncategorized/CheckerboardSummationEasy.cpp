#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> vg(m, vector<int>(n, 0)), psa(m + 1, vector<int>(n + 1, 0));
    while (true) {
        int r, c, x;
        cin >> r >> c >> x;
        if (r == 0 && c == 0 && x == 0) break;
        vg[r - 1][c - 1] = x;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            bool neg = (i + j) % 2;
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + (neg ? -vg[i - 1][j - 1] : vg[i - 1][j - 1]);
        }
    }
    while (true) {
        int r1, c1, r2, c2, ans;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0) break;
        bool neg = (r1 + c1) % 2;
        ans = psa[r2][c2] + psa[r1 - 1][c1 - 1] - psa[r1 - 1][c2] - psa[r2][c1 - 1];
        if (neg) ans = -ans;
        cout << ans << '\n';
    }
}