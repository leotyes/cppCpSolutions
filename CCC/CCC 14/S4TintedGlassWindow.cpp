#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    unsigned long long ans = 0;
    cin >> n >> t;
    map<pair<int, int>, int> diff;
    set<int> xs, ys;
    vector<vector<int>> vn(2005, vector<int>(2005, 0));
    vector<vector<int>> vdiff(2005, vector<int>(2005, 0));

    for (int i = 0; i < n; i++) {
        int xl, yt, xr, yb, ti;
        cin >> xl >> yt >> xr >> yb >> ti;

        diff[make_pair(yt, xl)] += ti;
        diff[make_pair(yt, xr)] -= ti;
        diff[make_pair(yb, xl)] -= ti;
        diff[make_pair(yb, xr)] += ti;

        xs.insert(xl);
        xs.insert(xr);
        ys.insert(yt);
        ys.insert(yb);
    }

    unordered_map<int, int> mxr, myr;

    int id = 0;
    for (auto x : xs) mxr[x] = id++;
    id = 0;
    for (auto y : ys) myr[y] = id++;

    for (auto [p, t] : diff) {
        auto [y, x] = p;
        vdiff[myr[y]][mxr[x]] = t;
    }

    for (int i = 0; i < ys.size(); i++) {
        for (int j = 0; j < xs.size(); j++) {
            vn[i + 1][j + 1] = vn[i][j + 1] + vn[i + 1][j] - vn[i][j] + vdiff[i][j];
        }
    }

    vector<int> vx(xs.begin(), xs.end()), vy(ys.begin(), ys.end());
    for (int i = 0; i + 1 < ys.size(); i++) {
        for (int j = 0; j + 1 < xs.size(); j++) {
            if (vn[i + 1][j + 1] >= t) {
                ans += (__int128)(vy[i + 1] - vy[i]) * (vx[j + 1] - vx[j]);
            }
        }
    }

    cout << ans;
}