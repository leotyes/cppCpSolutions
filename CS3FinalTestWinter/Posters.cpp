#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, n, ans = 0;

    cin >> x >> y >> n;

    vector<vector<bool>> vp(x + 1, vector<bool>(y + 1, false));

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                vp[j][k] = true;
            }
        }
    }

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (vp[i][j]) ans++;
        }
    }

    cout << ans;
}