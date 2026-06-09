#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    vector<tuple<int, int, int, int>> vs(k);
    for (int i = 0; i < k; i++) {
        int t, l, b, r;
        cin >> t >> l >> b >> r;
        vs[i] = make_tuple(t, l, b, r);
    }
    reverse(vs.begin(), vs.end());
    while (q--) {
        int x, y, curx, cury;
        cin >> x >> y;
        curx = x;
        cury = y;
        for (auto [t, l, b, r] : vs) {
            if (cury >= l && cury <= r && curx >= t && curx <= b) {
                int nx = t + r - cury, ny = l + curx - t;
                curx = nx;
                cury = ny;
            }
        }
        cout << (curx - 1) * n + cury << "\n";
    }
}