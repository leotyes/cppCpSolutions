#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w, h, n, ans = 0;
    cin >> w >> h >> n;
    vector<vector<int>> vp(h + 1, vector<int>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int x;
            cin >> x;
            vp[i][j] = x + vp[i - 1][j] + vp[i][j - 1] - vp[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = i; j <= h; j++) {
            int hh = j - i + 1;
            int ww = min(w, n / hh);
            if (ww == 0) continue;
            for (int k = ww; k <= w; k++) {
                int s = vp[j][k] - vp[i - 1][k] - vp[j][k - ww] + vp[i - 1][k - ww];
                ans = max(ans, s);
            }
        }
    }

    cout << ans;
}