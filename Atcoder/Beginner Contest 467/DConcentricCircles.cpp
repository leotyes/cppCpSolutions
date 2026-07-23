#include <bits/stdc++.h>
using namespace std;
#define int long long

tuple<int, int, int> perpbi(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    int c = dx * (x1 + x2) + dy * (y1 + y2);
    return {2 * dx, 2 * dy, c};
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

        auto l1 = perpbi(px, py, qx, qy);
        auto l2 = perpbi(rx, ry, sx, sy);

        auto [a1, b1, c1] = l1;
        auto [a2, b2, c2] = l2;

        __int128 det = (__int128)a1 * b2 - (__int128)a2 * b1;

        if (det != 0) {
            cout << "Yes\n";
        } else if ((__int128)a1 * c2 == (__int128)a2 * c1 && (__int128)b1 * c2 == (__int128)b2 * c1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}