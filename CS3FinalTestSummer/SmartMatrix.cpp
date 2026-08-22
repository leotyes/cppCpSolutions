#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> vn(n + 2, vector<int>(m + 2, 0)), vb(n + 2, vector<int>(m + 2, 0)), psa(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> vn[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (vn[i][j] + vn[i - 1][j - 1] - vn[i - 1][j] - vn[i][j - 1] != 0) {
                vb[i][j] = 1;
            } else {
                vb[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            psa[i][j] = vb[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    while (t--) {
        int r, c, k;
        cin >> r >> c >> k;
        if (k <= 1) {
            cout << "Y\n";
            continue;
        }
        int r1 = r + 1, r2 = r + k - 1, c1 = c + 1, c2 = c + k - 1;
        int s = psa[r2][c2] - psa[r1 - 1][c2] - psa[r2][c1 - 1] + psa[r1 - 1][c1 - 1];
        if (s == 0) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
}