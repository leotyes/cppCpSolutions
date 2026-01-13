#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;

    cin >> n;

    vector<vector<int>> vn(n, vector<int>(n)), mpsa(2 * n - 1, vector<int>()), spsa(2 * n - 1, vector<int>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vn[i][j];
            if (!mpsa[j - i + n - 1].empty()) {
                mpsa[j - i + n - 1].push_back(mpsa[j - i + n - 1].back() + vn[i][j]);
            } else {
                mpsa[j - i + n - 1].push_back(vn[i][j]);
            }
            if (!spsa[i + j].empty()) {
                spsa[i + j].push_back(spsa[i + j].back() + vn[i][j]);
            } else {
                spsa[i + j].push_back(vn[i][j]);
            }
        }
    }

    for (int sr = 0; sr < n; sr++) {
        for (int sc = 0; sc < n; sc++) {
            auto &tmpsa = mpsa[sc - sr + n - 1];
            pair<int, int> start, sstart;
            if (sc - sr < 0) {
                start = make_pair(-sc + sr, 0);
            } else {
                start = make_pair(0, sc - sr);
            }
            int msi = sr - start.first;
            for (int s = 2; s <= n - sc && s <= n - sr; s++) {
                int mei = s - 1 + msi;
                auto &tspsa = spsa[sr + sc + s - 1];
                if (sr + sc + s - 1 < n) {
                    sstart = make_pair(0, sr + sc + s - 1);
                } else {
                    sstart = make_pair(sr + sc + s - 1 - n + 1, n - 1);
                }
                int ssi = sr - sstart.first, sei = ssi + s - 1;
                ans = max(ans, tmpsa[mei] - (msi > 0 ? tmpsa[msi - 1] : 0) - tspsa[sei] + (ssi > 0 ? tspsa[ssi - 1] : 0));
            }
        }
    }

    cout << ans;
}